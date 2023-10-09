/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:36:40 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/09 20:21:55 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		i++;
	while (i--)
		free(splitted_args[i]);
	free(splitted_args);
}

void	argc_check(int *argc, char **argv, t_stack *a, t_stack *b)
{
	char	**splitted_argv;

	a->top_item = NULL;
	b->top_item = NULL;
	if (*argc < 2)
		(free_all(a, b), error());
	if (*argc == 2)
	{
		splitted_argv = ft_split(argv[1], ' ');
		if (args_checker_split(*argc, splitted_argv) == FALSE)
			(free_split(splitted_argv), free_all(a, b), error());
		stack_init_split(a, b, splitted_argv);
		free_split(splitted_argv);
	}
	else
	{
		if (args_checker(*argc, argv) == FALSE)
			(free_all(a, b), error());
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
	radix(a, b);
	if (sort_check(a) == TRUE && b->size == 0)
		ft_printf("\nOK\n");
	else
		ft_printf("\nKO\n");
	free_all(a, b);
	return (0);
}
