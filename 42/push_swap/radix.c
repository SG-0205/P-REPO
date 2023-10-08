/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:41:17 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/09 00:32:14 by sgoldenb         ###   ########.fr       */
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

size_t	neg_count(t_stack *stack)
{
	t_list_ps	*tmp;
	size_t		count;

	count = 0;
	if (!stack)
		return (0);
	if (stack->top_item)
		tmp = stack->top_item;
	while (tmp)
	{
		if (tmp->value < 0)
			count ++;
		tmp = tmp->next;
	}
	return (count);
}

t_bool	pos_check(t_stack *stack)
{
	t_list_ps	*tmp;

	if (!stack)
		return (ERROR);
	if (stack->top_item)
		tmp = stack->top_item;
	while (tmp)
	{
		if (tmp->value >= 0)
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

void	push_pos(int *i, int *b_mask, t_stack *a, t_stack *b)
{
	if (*i >= 0 && *i < __INT_MAX__)
		*b_mask = 1 << *i;
	else
		*b_mask = 0;
	if (a->top_item->value >= 0)
	ft_printf("Comparaison : %d & %d -> %d\n", a->top_item->value, *b_mask, (a->top_item->value & *b_mask));
	if ((a->top_item->value & *b_mask) == 0)
		push_b(a, b);
	else
		rotate_a(a, FALSE);
}

void	push_neg(int *i, int *b_mask, t_stack *a, t_stack *b)
{
	int	tmp_val;

	if (*i >= 0 && *i < __INT_MAX__)
		*b_mask = (1 << (sizeof(int) * 8 - 1)) << *i;
	else
		*b_mask = 0;
	// if (a->top_item->value < 0)
	// 	tmp_val = (a->top_item->value * -1);
	// else
		tmp_val = a->top_item->value;
	ft_printf("Comparaison : %d & %d -> %d\n", tmp_val, *b_mask, (tmp_val & *b_mask));
	if ((tmp_val & *b_mask) == 0)
		push_a(a, b);
	else
		rotate_b(b, FALSE);
}

void	radix_pos(t_stack *a, t_stack *b)
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
	ft_printf("VALMAX: %d\nPOS\n", max_size);
	while (++i <= max_size)
	{
		j = 0;
		while (j ++ < stack_size)
		{
			if (a->top_item->value >= 0)
				push_pos(&i, &b_mask, a, b);
			if (sort_check(a) == TRUE && rev_sort_check(b) == TRUE)
				break;
		}
		while (b->top_item && pos_check(b) == TRUE)
		{
			if (b->top_item->value >= 0)
				push_a(a, b);
			else
				rotate_b(b, FALSE);
		}
		if (sort_check(a) == TRUE && rev_sort_check(b) == TRUE)
			break;
	}
}

void	radix_neg(t_stack *a, t_stack *b)
{
	int	b_mask;
	int	i;
	int	max_size;
	int	stack_size;
	int j;
	
	max_size = get_maxval(b);
	stack_size = b->size;
	b_mask = 0;
	i = -1;
	ft_printf("VALMAX_N : %d\n", max_size);
	while (++i <= max_size)
	{
		j = 0;
		while (j ++ < stack_size && rev_sort_check(b) == FALSE)
		{
			if (b->top_item->value < 0 && rev_sort_check(b) == FALSE)
				push_neg(&i, &b_mask, a, b);
			ft_printf("LOL\n");
			if (rev_sort_check(b) == TRUE && neg_check(a) == FALSE)
				break;
		}
		while (neg_check(a) == TRUE)
		{
			if (a->top_item->value < 0)
				push_b(a, b);
		}
		if (rev_sort_check(b) == TRUE && sort_check(a) == TRUE)
			break;
	}
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

void	radix(t_stack *a, t_stack *b)
{
	if (neg_check(a) == TRUE)
	{		
		neg_sort(a, b);
		b_size_check(a, b);
		radix_neg(a, b);
		radix_pos(a, b);
		// while (rev_sort_check(b) == FALSE)
		// 	rotate_b(b, FALSE);
		while (b->top_item)
			push_a(a, b);
	}
	else
		radix_pos(a, b);
}