/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2_ch.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:43:30 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/13 17:25:47 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_b_ch(t_stack *b)
{
	t_list_ps	*tmp;

	if (!b || b->size == 0)
		return ;
	tmp = b->top_item;
	b->top_item = b->top_item->next;
	tmp->next = NULL;
	ft_lstadd_back_ps(&b->top_item, tmp);
	b->last_item = ft_lstlast_ps(b->top_item);
}

void	reverse_r_a_ch(t_stack *a)
{
	if (!a || a->size == 0)
		return ;
	if (a->size == 2)
		swap_a_ch(a);
	(ft_lstbflast(a->top_item))->next = NULL;
	ft_lstadd_front_ps(&a->top_item, a->last_item);
	a->top_item = a->last_item;
	a->last_item = ft_lstlast_ps(a->top_item);
}

void	reverse_r_b_ch(t_stack *b)
{
	if (!b || b->size == 0)
		return ;
	(ft_lstbflast(b->top_item))->next = NULL;
	ft_lstadd_front_ps(&b->top_item, b->last_item);
	b->top_item = b->last_item;
	b->last_item = ft_lstlast_ps(b->top_item);
}
