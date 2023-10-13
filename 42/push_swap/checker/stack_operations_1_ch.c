/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1_ch.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:43:30 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/13 16:12:18 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a_ch(t_stack *stack)
{
	t_list_ps	*tmp;

	if (stack->size < 2 || !stack)
		return ;
	tmp = stack->top_item;
	stack->top_item = tmp->next;
	tmp->next = stack->top_item->next;
	stack->top_item->next = tmp;
}

void	swap_b_ch(t_stack *stack)
{
	t_list_ps	*tmp;

	if (stack->size < 2 || !stack)
		return ;
	tmp = stack->top_item;
	stack->top_item = tmp->next;
	tmp->next = stack->top_item->next;
	stack->top_item->next = tmp;
}

void	push_a_ch(t_stack *a, t_stack *b)
{
	t_list_ps	*tmp;

	if (!b || !a || b->size == 0)
		return ;
	tmp = b->top_item;
	b->top_item = b->top_item->next;
	tmp->next = a->top_item;
	b->size --;
	a->top_item = tmp;
	a->size ++;
	a->last_item = ft_lstlast_ps(a->top_item);
	if (b->size == 0)
		b->last_item = NULL;
}

void	push_b_ch(t_stack *a, t_stack *b)
{
	t_list_ps	*tmp;

	if (!b || !a || a->size == 0)
		return ;
	tmp = a->top_item;
	a->top_item = a->top_item->next;
	tmp->next = b->top_item;
	a->size --;
	b->top_item = tmp;
	b->size ++;
	b->last_item = ft_lstlast_ps(b->top_item);
	if (a->size == 0)
		a->last_item = NULL;
}

void	rotate_a_ch(t_stack *a)
{
	t_list_ps	*tmp;

	if (!a || a->size == 1)
		return ;
	tmp = a->top_item;
	a->top_item = a->top_item->next;
	tmp->next = NULL;
	ft_lstadd_back_ps(&a->top_item, tmp);
	a->last_item = ft_lstlast_ps(a->top_item);
}
