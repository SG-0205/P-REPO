/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:56:40 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/09 19:58:24 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_maxlen(t_stack *stack)
{
	t_list_ps	*tmp;
	int			len;
	int			current;

	len = 0;
	if (!stack)
		return (0);
	if (stack->top_item)
		tmp = stack->top_item;
	while (tmp)
	{
		current = 0;
		ft_intlen2(tmp->value, &current);
		if (current > len)
			len = current;
		tmp = tmp->next;
	}
	return (len);
}

int	dist_from_top_n(t_stack *stack)
{
	t_list_ps	*tmp;
	int			distance;

	distance = 0;
	if (stack->top_item)
		tmp = stack->top_item;
	while (tmp)
	{
		if (tmp->value < 0)
			return (distance);
		distance ++;
		tmp = tmp->next;
	}
	return (distance);
}

void	neg_sort(t_stack *a, t_stack *b)
{
	int	stack_size;

	stack_size = a->size;
	while (neg_check(a) == TRUE && a->top_item)
	{
		if (a->top_item->value < 0)
			push_b(a, b);
		else if (dist_from_top_n(a) > stack_size / 2)
			reverse_r_a(a, FALSE);
		else if (dist_from_top_n(a) <= stack_size / 2)
			rotate_a(a, FALSE);
		else
			break ;
	}
}

int	get_maxval(t_stack *stack)
{
	t_list_ps	*tmp;
	int			ret;
	int			tmp_val;

	ret = 0;
	if (stack->top_item)
		tmp = stack->top_item;
	while (tmp)
	{
		tmp_val = tmp->value;
		if (tmp_val < 0)
			tmp_val = -tmp_val;
		if (ret < tmp_val)
			ret = tmp_val;
		tmp = tmp->next;
	}
	return (ret);
}

void	b_size_check(t_stack *a, t_stack *b)
{
	if (b->size == 1)
		return ;
	else if (b->size == 2 && rev_sort_check(b) == FALSE)
		swap_b(b, FALSE);
	else if (b->size == 3)
		sort_three_rev(b, swap_b, reverse_r_b);
	else if (b->size < 6)
		sort5_rev(a, b);
}
