/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:13:12 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/09 19:47:27 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putendl("Error");
	exit(0);
}

void	free_from_top(t_stack *stack, t_stack *empty)
{
	if (!stack)
		return ;
	ft_lstclear_ps(&stack->top_item);
	free(stack);
	free(empty);
	error();
}

int	check_doub_int(t_stack *a)
{
	t_list_ps	*tmp;
	t_list_ps	*tmp2;

	tmp = a->top_item;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->value == tmp->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	stack_init(t_stack *a, t_stack *b, int argc, char **argv)
{
	int			i;
	t_list_ps	*new;
	t_list_ps	*top;

	i = 2;
	top = ft_lstnew_ps(ft_atoi(argv[1]));
	if (!top)
		error();
	while (i < argc)
	{
		new = ft_lstnew_ps(ft_atoi(argv[i]));
		if (!new)
			ft_lstclear_ps(&top);
		ft_lstadd_back_ps(&top, new);
		i ++;
	}
	a->size = (argc - 1);
	a->top_item = top;
	a->last_item = ft_lstlast_ps(top);
	b->last_item = NULL;
	b->top_item = NULL;
	b->size = 0;
	if (check_doub_int(a) == 1)
		free_from_top(a, b);
}

void	stack_init_split(t_stack *a, t_stack *b, char **argv)
{
	int			i;
	t_list_ps	*new;
	t_list_ps	*top;

	i = 0;
	top = ft_lstnew_ps(ft_atoi(argv[0]));
	if (!top)
		error();
	while (argv[++i])
	{
		new = ft_lstnew_ps(ft_atoi(argv[i]));
		if (!new)
			ft_lstclear_ps(&top);
		ft_lstadd_back_ps(&top, new);
	}
	a->size = (i);
	a->top_item = top;
	a->last_item = ft_lstlast_ps(top);
	b->last_item = NULL;
	b->top_item = NULL;
	b->size = 0;
	if (check_doub_int(a) == 1)
		(free_split(argv), free_from_top(a, b));
}
