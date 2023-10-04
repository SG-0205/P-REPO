/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:36:40 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/04 20:34:25 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printstack(t_stack *stack, char name)
{
	t_list_ps	*tmp;

	if (!stack)
		return ;
	ft_printf("Stack %c\n", name);
	if (!stack->top_item)
		return ;
	tmp = stack->top_item;
	while (tmp)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	if (stack->top_item)
		ft_printf("1st : %d\n", stack->top_item->value);
	if (stack->last_item)
		ft_printf("Lst : %d\n", stack->last_item->value);	
	ft_printf("SIZE : %d\n", stack->size);
}

int	free_all(t_stack *a, t_stack *b)
{
	if (!a && !b)
		return (0);
	if (a && a->top_item)
		ft_lstclear_ps(&a->top_item), a->last_item = NULL;
	if (b && b->top_item)
		ft_lstclear_ps(&b->top_item);
	printstack(a, 'a'), printstack(b, 'b');
	if (a)
		free(a);
	if (b)
		free(b);
	return (TRUE);
}

int	sort3_return(t_stack *a, t_stack *b)
{
	if (!a || !b)
		error();
	sort_three(a, swap_a, reverse_r_a);
	return (free_all(a, b));
}

int	sort5_return(t_stack *a, t_stack *b)
{
	if (!a || !b)
		error();
	while (a->size > 3)
		push_b(a, b);
	if (b->top_item->value > b->last_item->value)
		swap_b(b, FALSE);
	sort_three(a, swap_a, reverse_r_a);
	while (b->size != 0) 
	{
		push_a(a, b);
		if (a->top_item->value > (ft_lstbflast(a->top_item)->value)
		&& a->top_item->value < a->last_item->value)
			reverse_r_a(a, FALSE), swap_a(a, FALSE),
			rotate_a(a, FALSE), rotate_a(a, FALSE);
		else if (a->top_item->value > a->last_item->value)
			rotate_a(a, FALSE);
		else if (a->top_item->value > a->top_item->next->value)
			swap_a(a, FALSE);
	}
	printstack(a, 'a'), printstack(b, 'b');
	if (sort_check(a) == TRUE)
		return (free_all(a, b));
	return (FALSE);
}

t_bool	initial_parse(t_stack *a, t_stack *b)
{
	if (sort_check(a) ==  TRUE)
		return (free_all(a, b));
	if (a->size == 3)
		return (sort3_return(a, b));
	else if (a->size == 5 || a->size == 4)
		return (sort5_return(a, b));
	return(FALSE);
}

t_bool	is_max(t_stack *stack)
{
	t_list_ps	*tmp;
	int			top_val;

	if (!stack->top_item)
		return (FALSE);
	tmp = stack->top_item;
	top_val = tmp->value;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp->value > top_val)
			return (FALSE);
	}
	return (TRUE);
}

void	free_split(char **splitted_args)
{
	size_t	i;

	i = 0;
	while (splitted_args[i])
		i ++;
	while (i --)
		free(splitted_args[i]);
	free(splitted_args);
}

void	argc_check(int *argc, char **argv, t_stack *a, t_stack *b)
{
	char	**splitted_argv;

	if (*argc < 2)
		error();
	if (*argc == 2)
	{
		splitted_argv = ft_split(argv[1], ' ');
		args_checker_split(*argc, splitted_argv);
		stack_init_split(a, b, splitted_argv);
		free_split(splitted_argv);
	}
	else
	{
		args_checker(*argc, argv);
		stack_init(a, b, *argc, argv);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	if (argc < 1)
		return (0);
	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		error();
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		error();
	argc_check(&argc, argv, a, b);
	if (initial_parse(a, b) == TRUE)
		return (0);
	// printstack(a, 'a'), printstack(b, 'b');
	radix(a, b);
	// quick_sort_a(a, b);
	printstack(a, 'a'), printstack(b, 'b');
	if (sort_check(a) == TRUE && b->size == 0)
		ft_printf("\nOK\n");
	else
		ft_printf("\nKO\n");
	// printstack(a, 'a');
	free_all(a, b);
	return (0);
}