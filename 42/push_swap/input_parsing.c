/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:26:30 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/09 19:27:07 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_all(t_stack *a, t_stack *b)
{
	if (!a && !b)
		return (0);
	if (a && a->top_item)
		(ft_lstclear_ps(&a->top_item), a->last_item = NULL);
	if (b && b->top_item)
		ft_lstclear_ps(&b->top_item);
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

void	sort5_rev(t_stack *a, t_stack *b)
{
	if (!a || !b)
		error();
	while (b->size > 3)
		push_a(a, b);
	if (neg_count(a) > 1 && a->top_item->value < b->top_item->next->value)
		swap_a(a, FALSE);
	sort_three_rev(b, swap_b, reverse_r_b);
	while (neg_check(a) == TRUE)
	{
		push_b(a, b);
		if (b->top_item->value < (ft_lstbflast(b->top_item)->value)
			&& b->top_item->value > b->last_item->value)
			(reverse_r_b(b, FALSE), swap_b(b, FALSE), rotate_b(b, FALSE),
				rotate_b(b, FALSE));
		else if (b->top_item->value < b->last_item->value)
			rotate_b(b, FALSE);
		else if (b->top_item->value > b->top_item->next->value)
			swap_b(b, FALSE);
	}
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
			(reverse_r_a(a, FALSE), swap_a(a, FALSE), rotate_a(a, FALSE),
				rotate_a(a, FALSE));
		else if (a->top_item->value > a->last_item->value)
			rotate_a(a, FALSE);
		else if (a->top_item->value > a->top_item->next->value)
			swap_a(a, FALSE);
	}
	if (sort_check(a) == TRUE)
		return (free_all(a, b));
	return (FALSE);
}

t_bool	initial_parse(t_stack *a, t_stack *b)
{
	if (sort_check(a) == TRUE)
		return (free_all(a, b));
	if (a->size == 3)
		return (sort3_return(a, b));
	else if (a->size == 5 || a->size == 4)
		return (sort5_return(a, b));
	return (FALSE);
}
