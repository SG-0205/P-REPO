/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:41:17 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/14 19:31:28 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	neg_check(t_stack *stack)
{
	t_list_ps	*tmp;

	if (!stack)
		return (ERROR);
	if (stack->top_item)
		tmp = stack->top_item;
	while (tmp)
	{
		if (tmp->value < 0)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

int	power10(int power)
{
	int	res;
	res = 10;
	while (power-- != 1)
		res *= 10;
	return (res);
}

void	ft_intlen2(long int n, int *len)
{
	unsigned int	ln;

	ln = n;
	if (n < 0)
	{
		*len += 1;
		ln = -n;
	}
	if (ln > 9)
	{
		*len += 1;
		ft_intlen2(ln / 10, len);
	}
	else
		*len += 1;
}

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

void	neg_sort(t_stack *a, t_stack *b)
{
	while (neg_check(a) == TRUE && a->size != 1)
	{
		ft_printf("SORT");
		if (a->top_item->value < 0)
			push_b(a, b);
		else if (a->last_item->value < 0)
			reverse_r_a(a, FALSE);
		else if (a->top_item->next && a->top_item->next->value < 0)
			swap_a(a, FALSE);
		else if (a->top_item->next && a->top_item->next->value > 0)
			rotate_a(a, FALSE);
		else if (a->last_item->value > 0
		&& a->top_item->value > 0)
			rotate_a(a, FALSE);
		else
			break;
	}
}


void	radix(t_stack *stack, t_stack *box, int scope)
{
	int	box_i;
	
	box_i = 0;
	while (stack->size != 0 && stack && stack->top_item)
	{
		if (stack->top_item->value % scope == box_i)
			push_b(box, FALSE);
		else if (stack->last_item->value % scope == box_i)
			reverse_r_a(stack, FALSE);
		else if (stack->top_item->next
		&& stack->top_item->next->value % scope == box_i)
			rotate_a(stack, FALSE);
		else	
			box_i ++;
	}
}