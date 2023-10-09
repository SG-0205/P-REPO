/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:41:17 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/09 20:26:54 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_pos(int *i, t_stack *a, t_stack *b)
{
	int	b_mask;

	if (*i >= 0 && *i < __INT_MAX__)
		b_mask = 1 << *i;
	else
		b_mask = 0;
	if ((a->top_item->value & b_mask) == 0)
		push_b(a, b);
	else
		rotate_a(a, FALSE);
}

void	push_neg(int *i, t_stack *a, t_stack *b)
{
	int	b_mask;

	if (*i >= 0 && *i < __INT_MAX__)
		b_mask = 1 << *i;
	else
		b_mask = 0;
	if ((-b->top_item->value & b_mask) == 0)
		push_a(a, b);
	else
		rotate_b(b, FALSE);
}

void	radix_pos(t_stack *a, t_stack *b)
{
	int	i;
	int	max_size;
	int	stack_size;
	int	j;

	max_size = get_maxval(a);
	stack_size = a->size;
	i = -1;
	while (++i <= max_size)
	{
		j = 0;
		while (j++ < stack_size && sort_check(a) == FALSE)
			push_pos(&i, a, b);
		while (b->top_item && pos_check(b) == TRUE)
		{
			if (b->top_item->value >= 0)
				push_a(a, b);
			else
				rotate_b(b, FALSE);
		}
		if (sort_check(a) == TRUE && rev_sort_check(b) == TRUE)
			break ;
	}
}

void	radix_neg(t_stack *a, t_stack *b)
{
	int	i;
	int	max_size;
	int	stack_size;
	int	j;

	max_size = get_maxval(b);
	stack_size = b->size;
	i = -1;
	ft_printf("VALMAX_N : %d\n", max_size);
	while (++i <= max_size)
	{
		j = 0;
		while (j++ < stack_size && rev_sort_check(b) == FALSE)
			if (b->top_item->value < 0)
				push_neg(&i, a, b);
		while (neg_check(a) == TRUE)
			if (a->top_item->value < 0)
				push_b(a, b);
		if (rev_sort_check(b) == TRUE)
			break ;
	}
}

void	radix(t_stack *a, t_stack *b)
{
	if (neg_check(a) == TRUE)
	{
		neg_sort(a, b);
		(b_size_check(a, b), radix_neg(a, b), radix_pos(a, b));
		while (b->top_item)
			push_a(a, b);
	}
	else
		radix_pos(a, b);
}
