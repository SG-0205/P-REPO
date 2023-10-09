/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:45:15 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/09 19:38:05 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	sort_check(t_stack *a)
{
	t_list_ps	*tmp;

	tmp = a->top_item;
	while (tmp)
	{
		if (tmp->next && tmp->value > tmp->next->value)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

t_bool	check_rest(t_list_ps *start)
{
	t_list_ps	*tmp;

	tmp = start;
	while (tmp)
	{
		if (tmp->next && tmp->value > tmp->next->value)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

t_bool	rev_sort_check(t_stack *a)
{
	t_list_ps	*tmp;

	if (!a || !a->top_item)
		return (TRUE);
	tmp = a->top_item;
	while (tmp)
	{
		if (tmp->next && tmp->value < tmp->next->value)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

void	sort_three_rev(t_stack *stack, void (*swap)(t_stack *, t_bool),
void (*reverse_r)(t_stack *, t_bool))
{
	if (!stack->top_item)
		return ;
	if (stack->size != 3)
		return ;
	while (1)
	{
		if (stack->top_item->next
			&& stack->top_item->value > stack->top_item->next->value
			&& stack->last_item->value < stack->top_item->next->value)
			break ;
		else if (stack->top_item->value < stack->top_item->next->value)
			(*swap)(stack, FALSE);
		else if (stack->last_item->value > stack->top_item->next->value)
			(*reverse_r)(stack, FALSE);
	}
}

void	sort_three(t_stack *stack, void (*swap)(t_stack *, t_bool),
void (*reverse_r)(t_stack *, t_bool))
{
	if (!stack->top_item)
		return ;
	if (stack->size != 3)
		return ;
	while (1)
	{
		if (stack->top_item->next
			&& stack->top_item->value < stack->top_item->next->value
			&& stack->last_item->value > stack->top_item->next->value)
			break ;
		else if (stack->top_item->value > stack->top_item->next->value)
			(*swap)(stack, FALSE);
		else if (stack->last_item->value < stack->top_item->next->value)
			(*reverse_r)(stack, FALSE);
	}
}
