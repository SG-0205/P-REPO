/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 22:26:31 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/07 20:58:38 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	operations_init(void **functions, char name)
{
	if (!functions)
		return ;
	if (name == 'a')
	{
		functions[0] = push_b;
		functions[1] = reverse_r_a;
		functions[2] = swap_a;
		functions[3] = rotate_a;
		return ;
	}
	if (name == 'b')
	{
		functions[0] = push_a;
		functions[1] = reverse_r_b;
		functions[2] = swap_b;
		functions[3] = rotate_b;
		return ;
	}
}

static void	sort(t_stack *a, t_stack *b, int pivot_value, char name)
{
	void	**operations;
	
	operations = (void **)malloc(4 * sizeof(void *));
	operations_init(operations, name);
	while (1)
	{
		printstack(a, name);
		if (a->top_item->value < pivot_value)
			push_b(a, b);
		else if (a->last_item->value < pivot_value)
			reverse_r_a(a, FALSE);
		else if (a->top_item->next && a->top_item->next->value < pivot_value)
			swap_a(a, FALSE);
		else if (a->top_item->next && a->top_item->next->value > pivot_value)
			rotate_a(a, FALSE);
		else
			break;
	}
}

void	quick_sort(t_stack *a, t_stack *b, char from_name)
{
	int			pivot_value;

	pivot_value = (get_median_item(a, get_median(a)))->value;
	ft_printf("\nPIVOT : %d\n", pivot_value);
	sort(a, b, pivot_value, from_name);
	if (end_check(a, 'a', swap_a) == FALSE)
		quick_sort(a, b, 'a');
	// printstack(a, 'a');
}
