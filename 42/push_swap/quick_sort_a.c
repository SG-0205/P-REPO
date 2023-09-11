/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 22:26:31 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/11 22:00:41 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_pivot(t_stack *stack, int *pivot_value)
{
	t_list_ps	*tmp;

	tmp = stack->top_item;
	while (tmp)
	{
		if (tmp->value < *pivot_value)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

void	pv_check(int *pivot_value, t_stack *a)
{
	t_list_ps	*tmp;

	if (!a->top_item)
		return;
	tmp = a->top_item;
	while (tmp && tmp->value >= *pivot_value)
		tmp = tmp->next;
	if (tmp == NULL && get_median_item(a, get_median(a))->next)
		*pivot_value = get_median_item(a, get_median(a))->next->value;
	else
		*pivot_value = a->top_item->value;
}

static void	order_b(t_stack *b)
{
	while (rev_sort_check(b) == FALSE)
	{
		if (!b->top_item)
			return ;
		if (b->size == 3)
			sort_three(b, swap_b, reverse_r_b);
		else if (b->top_item->next
		&& b->top_item->value < b->top_item->next->value)
			swap_b(b, FALSE);
		else if (b->last_item
		&& b->top_item->value < b->last_item->value)
			rotate_b(b, FALSE);
		else if (b->last_item
		&& b->top_item->value < b->last_item->value)
		else
			break;
	}
	printstack(b, 'b');
}

static void	sort_a(t_stack *a, t_stack *b, int *pivot_value, char name)
{
	while (check_pivot(a, pivot_value) != TRUE && a->size != 1)
	{
		if (a->top_item->value < *pivot_value)
			push_b(a, b), order_b(b);
		else if (a->last_item->value < *pivot_value)
			reverse_r_a(a, FALSE), order_b(b);
		else if (a->top_item->next && a->top_item->next->value < *pivot_value)
			swap_a(a, FALSE), order_b(b);
		else if (a->top_item->next && a->top_item->next->value > *pivot_value)
			rotate_a(a, FALSE), order_b(b);
		else if (a->last_item->value > *pivot_value
		&& a->top_item->value > *pivot_value)
			rotate_a(a, FALSE), order_b(b);
		else
			break;
	}
	printstack(a, name);
}

void	keep_pivot_a(t_stack *a, t_stack *b, int *pivot_value)
{
	while (a->top_item && a->size != 1)
	{
		if (a->top_item->value == *pivot_value)
			rotate_a(a, FALSE);
		else
			push_b(a, b);
	}
}

void	quick_sort_a(t_stack *a, t_stack *b, char from_name)
{
	int pivot_value;
	
	pivot_value = (get_median_item(a, get_median(a))->value);
	pv_check(&pivot_value, a);	
	ft_printf("\nPIVOT : %d\n", pivot_value);
	if (a->size == 3)
		sort_three(a, swap_a, reverse_r_a);
	sort_a(a, b, &pivot_value, from_name);
	// if (end_check(b, 'b', swap_b) == FALSE)
	// 	quick_sort_b(a, b, 'b');
	printstack(b, 'b');
	if (sort_check(a) == FALSE)
		quick_sort_a(a, b, 'a');
	while (b->size > 0)
		push_a(a, b);
	printstack(a, 'a');
}