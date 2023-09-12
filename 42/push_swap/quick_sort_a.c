/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 22:26:31 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/12 20:35:35 by sgoldenb         ###   ########.fr       */
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

void	order_b(t_stack *b)
{
	if (rev_sort_check(b) == FALSE && b->top_item && b->last_item)
	{
		ft_printf("ORDER");
		if (b->size == 3)
			sort_three_rev(b, swap_b, reverse_r_b);
		else if (b->top_item->next
		&& b->top_item->value > b->top_item->next->value
		&& b->top_item->next->value > b->last_item->value)
			rotate_b(b, FALSE);
		else if (b->last_item && b->top_item->next
		&& b->top_item->value > b->last_item->value
		&& b->top_item->next->value < b->top_item->value)
			reverse_r_b(b, FALSE), order_b(b);
		else if (b->top_item->next
		&& b->top_item->value < b->top_item->next->value)
			swap_b(b, FALSE), order_b(b);
	}
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
	else if (tmp == NULL && !(get_median_item(a, get_median(a))->next))
		*pivot_value = a->top_item->next->value;
}

void	merge(t_stack *a, t_stack *b)
{
	while ((/*sort_check(a) == FALSE && */rev_sort_check(b) == FALSE)
	&& b->size > 3 && a && b && a->top_item && b->top_item)
	{
		ft_printf("MERGE");
		if (b->top_item->next
		&& a->top_item->value > b->top_item->value
		&& b->top_item->value > b->top_item->next->value)
			push_a(a, b);
		else if (a->top_item->value < b->top_item->value
		&& a->top_item)
			swap_b(b, FALSE), merge(a, b);
		else if (b->top_item->next
		&& a->top_item->value < b->last_item->value
		&& a->top_item->value > b->top_item->value)
			rotate_b(b, FALSE), merge(a, b);
		else if (a->top_item->value > b->last_item->value
		&& a->top_item->value > b->top_item->value)
			reverse_r_b(b, FALSE), merge(a, b);
		// else if (b->top_item->next
		// && (a->top_item->value < b->top_item->value
		// && a->top_item->value < b->top_item->next->value))
		// 	rotate_b(b, FALSE), merge(a, b);
		else
			break;
	}
}

static void	sort_a(t_stack *a, t_stack *b, int *pivot_value)
{
	while (check_pivot(a, pivot_value) != TRUE && a->size != 1)
	{
		ft_printf("SORT");
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
	// (void)printstack(a, name);
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

void	quick_sort_a(t_stack *a, t_stack *b)
{
	int pivot_value;
	
	pivot_value = (get_median_item(a, get_median(a))->value);
	pv_check(&pivot_value, a);	
	if (a->size <= 3)
		sort_three(a, swap_a, reverse_r_a);
	sort_a(a, b, &pivot_value);
	// printstack(b, 'b');
	if (sort_check(a) == FALSE)
		quick_sort_a(a, b);
	// if (rev_sort_check(b) == FALSE)
	// 	order_b(b);
	// merge(a, b);
	while (b->size != 0)
		push_a(a, b);
	if (sort_check(a) == FALSE)
		quick_sort_a(a, b);
	// printstack(a, 'a');
}