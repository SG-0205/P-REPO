/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:45:15 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/11 16:22:49 by sgoldenb         ###   ########.fr       */
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

void	sort_three(t_stack *stack, void (*swap)(t_stack *, t_bool),
void (*reverse_r)(t_stack *, t_bool))
{
	if (stack->size != 3)
		return ;
	while (1)
	{
		if (stack->top_item->value < stack->top_item->next->value
		&& stack->last_item->value > stack->top_item->next->value)
			break;
		else if (stack->top_item->value > stack->top_item->next->value)
			(*swap)(stack, FALSE);
		else if (stack->last_item->value < stack->top_item->next->value)
			(*reverse_r)(stack, FALSE);
	}
}

t_bool	end_check(t_stack *stack, char name, void (*swap)(t_stack *, t_bool))
{
	if (stack->size == 0 && name == 'b')
		return (TRUE);
	if (stack->size == 3)
	{
		if (name == 'a')
			sort_three(stack, swap_a, reverse_r_a);
		if (name == 'b')
			sort_three(stack, swap_b, reverse_r_b);
	}
	if (stack->size == 2)
		if (stack->top_item->value > stack->top_item->next->value)
			(*swap)(stack, FALSE);
	if (sort_check(stack) == TRUE)
		return (TRUE);
	return (FALSE);
}