/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:43:30 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/13 15:36:21 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_stack *b, t_bool rr)
{
	t_list_ps	*tmp;

	if (!b || b->size == 0)
		return ;
	tmp = b->top_item;
	b->top_item = b->top_item->next;
	tmp->next = NULL;
	ft_lstadd_back_ps(&b->top_item, tmp);
	b->last_item = ft_lstlast_ps(b->top_item);
	if (rr == FALSE)
		ft_putendl("rb");
}

void	reverse_r_a(t_stack *a, t_bool rrr)
{
	if (!a || a->size == 0)
		return ;
	if (a->size == 2)
		swap_a(a, FALSE);
	(ft_lstbflast(a->top_item))->next = NULL;
	ft_lstadd_front_ps(&a->top_item, a->last_item);
	a->top_item = a->last_item;
	a->last_item = ft_lstlast_ps(a->top_item);
	if (rrr == FALSE)
		ft_putendl("rra");
}

void	reverse_r_b(t_stack *b, t_bool rrr)
{
	if (!b || b->size == 0)
		return ;
	(ft_lstbflast(b->top_item))->next = NULL;
	ft_lstadd_front_ps(&b->top_item, b->last_item);
	b->top_item = b->last_item;
	b->last_item = ft_lstlast_ps(b->top_item);
	if (rrr == FALSE)
		ft_putendl("rrb");
}
