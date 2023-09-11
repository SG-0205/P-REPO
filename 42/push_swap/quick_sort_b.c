/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:36:20 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/11 19:06:27 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b(t_stack *a, t_stack *b, int *pivot_value, char name)
{
	while (check_pivot(b, pivot_value) != TRUE && b->size != 0)
	{
		if (b->top_item->value < *pivot_value)
			(push_a(a, b));
		else if (b->last_item->value < *pivot_value)
			reverse_r_b(b, FALSE);
		else if (b->top_item->next && b->top_item->next->value < *pivot_value)
			swap_b(b, FALSE);
		else if (b->top_item->next && b->top_item->next->value > *pivot_value)
			rotate_b(b, FALSE);
		else if (b->last_item->value > *pivot_value
		&& b->top_item->value > *pivot_value)
			rotate_b(b, FALSE);
		else
			break;
	}
	printstack(b, name);
}

void	keep_pivot_b(t_stack *a, t_stack *b, int *pivot_value)
{
	while (b->top_item && b->size != 2)
	{
		if (b->top_item->value == *pivot_value)
			rotate_b(b, FALSE);
		else
			push_a(a, b);
	}
}

void	quick_sort_b(t_stack *a, t_stack *b, char from_name)
{
	int pivot_value;
	
	pivot_value = (get_median_item(b, get_median(b))->value);	
	ft_printf("\nPIVOT : %d\n", pivot_value);
	if (b->size == 3)
		sort_three(b, swap_b, reverse_r_b);
	sort_b(a, b, &pivot_value, from_name);
	// if (end_check(b, 'b', swap_b) == FALSE)
	// 	quick_sort_b(a, b, 'b');
	printstack(a, 'a');
	if (sort_check(b) == FALSE)
		quick_sort_b(a, b, 'a');
	while (b->size > 0)
		push_a(a, b);
	printstack(a, 'a');
}