/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:41:17 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/21 21:59:46 by sgoldenb         ###   ########.fr       */
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
	while (power-- > 1)
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
		// ft_printf("SORT");
		if (a->top_item->value < 0)
			push_b(a, b);
		else if (a->last_item->value < 0)
			reverse_r_a(a, FALSE);
		else if (a->top_item->next && a->top_item->next->value < 0)
			swap_a(a, FALSE);
		else if (a->top_item->next && a->top_item->next->value > 0)
			rotate_a(a, FALSE);
		else if (a->last_item->value > 0 && a->top_item->value > 0)
			rotate_a(a, FALSE);
		else
			break ;
	}
}

t_bool	scope_validation(int *nb, int *scope, int *box)
{
	int	nb_len;
	int	scope_len;

	nb_len = 0;
	scope_len = 0;
	ft_intlen2(*nb, &nb_len);
	ft_intlen2(*scope, &scope_len);
	// ft_printf("\nnb_len : %d\tscope_len : %d\n", nb_len, scope_len);
	if ((*scope == 1) && (*nb % 10 == *box))
		return (TRUE);
	else if (nb_len < scope_len && *box == 0)
		return (TRUE);
	else if (scope_len > 1 && nb_len == scope_len && (*nb / *scope == *box))
		return (TRUE);
	else if (scope_len > 1 && nb_len != scope_len && nb_len > 1
	&& (*nb / *scope) % 10 == *box)
		return (TRUE);
	else
		return (FALSE);		
}

t_bool	scope_check(t_stack *stack, int *mask)
{
	t_list_ps	*tmp;
	int			val_tmp;

	if (stack->top_item)
		tmp = stack->top_item;
	// ft_printf("SCOPE_CHECK\n");
	while (tmp)
	{
		// printstack(stack, 'a');
		if (tmp->value < 0)
			val_tmp = -tmp->value;
		else
			val_tmp = tmp->value;
		// ft_printf("VALIDATING\n");
		if ((val_tmp & *mask) == 0)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

int	dist_from_top(t_stack *stack, int *scope, int *box)
{
	t_list_ps	*tmp;
	int			distance;

	distance = 0;
	if (!stack)
		return (0);
	if (stack->top_item)
		tmp = stack->top_item;
	while (tmp)
	{
		// ft_printf("DIST: %d\tSIZE: %d\n", distance, stack->size);
		if (scope_validation(&tmp->value, scope, box) == TRUE)
			return (distance);
		distance ++;
		tmp = tmp->next;
	}
	return (distance);
}

int	create_radix_env(t_stack **group, t_stack *a, t_stack *b, int *scope)
{
	int	scope_len;
	
	scope_len = 0;
	group = (t_stack **)malloc(2 * (sizeof (t_stack *)));
	group[0] = a;
	group[1] = b;
	ft_intlen2(*scope, &scope_len);
	return (scope_len);
}

void	final_sort(t_stack *a, t_stack *b)
{
	while (b->top_item)
	{
		// printstack(a, 'a'), printstack(b, 'b');
		if (!a->top_item  || b->top_item->value < a->top_item->value)
			push_a(a, b);
		else if (b->top_item->next
		&& b->top_item->next->value < a->top_item->value
		&& b->top_item->value < b->top_item->next->value)
			swap_b(b, FALSE);
		else if (b->last_item->value < a->top_item->value)
			reverse_r_b(b, FALSE);
		else if (b->top_item->value > a->top_item->value)
			rotate_b(b, FALSE);
	}
}

int	error_index(t_stack *stack)
{
	t_list_ps	*tmp;
	t_list_ps	*prev;
	int			index;
	
	index = 0;
	if (stack->top_item)
		prev = stack->top_item;
	if (stack->top_item->next)
		tmp = stack->top_item->next;
	while (tmp->next->next)
	{
		if (tmp->value > tmp->next->value
		&& tmp->value > prev->value)
			return (index);
		prev = tmp;
		tmp = tmp->next;
		index ++;
	}
	return (0);
}

int	get_maxval(t_stack *stack)
{
	t_list_ps	*tmp;
	int			ret;

	ret = 0;
	if (stack->top_item)
		tmp = stack->top_item;
	while (tmp)
	{
		if (ret < tmp->value)
			ret = tmp->value;
		tmp = tmp->next;
	}
	return (ret);
}

void	radix(t_stack *a, t_stack *b)
{
	int	b_mask;
	int	i;
	int	max_size;
	int	stack_size;
	int j;
	
	max_size = get_maxval(a);
	stack_size = a->size;
	b_mask = 0;
	i = -1;
	while (++i <= max_size)
	{
		j = 0;
		while (j ++ < stack_size)
		{
			if (i >= 0 && i < __INT_MAX__)
				b_mask = 1 << i;
			else
				b_mask = 0;
			if ((a->top_item->value & b_mask) == 0)
				push_b(a, b);
			else
				rotate_a(a, FALSE);
			if (sort_check(a) == TRUE && rev_sort_check(b) == TRUE)
				break;
		}
		while (b->top_item)
			push_a(a, b);
		if (sort_check(a) == TRUE)
			break;
	}
}