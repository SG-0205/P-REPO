/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:36:40 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/21 18:59:48 by sgoldenb         ###   ########.fr       */
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
	if (!a || !b)
		return (0);
	if (a->top_item)
		ft_lstclear_ps(&a->top_item), a->last_item = NULL;
	if (b->top_item)
		ft_lstclear_ps(&b->top_item);
	printstack(a, 'a'), printstack(b, 'b');
	free(a);
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
	args_checker(argc, argv), stack_init(a, b, argc, argv);
	if (initial_parse(a, b) == TRUE)
		return (0);
	// quick_sort_a(a, b);
	// ft_printf("last_ptr :\t%p\n", a->last_item->next);
	int scope = 0, scope_len = 0, i = 0;
	// max_len = get_maxlen(a);
	while (i < 15)
	{
		// ft_printf("MAXLEN: %d\nSCOPELEN: %d\n", max_len, scope_len);
		ft_intlen2(scope, &scope_len);
		radix(a, b, &scope);
		scope ++;
		i ++;
	}
	if (sort_check(a) == TRUE && b->size == 0)
		ft_printf("\nOK\n");
	else
		ft_printf("\nKO\n");
	printstack(a, 'a');
	free_all(a, b);
	return (0);
}