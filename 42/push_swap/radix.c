/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:41:17 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/15 17:26:59 by sgoldenb         ###   ########.fr       */
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
		ft_printf("SORT");
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
	ft_printf("\nnb_len : %d\tscope_len : %d", nb_len, scope_len);
	if ((scope_len == 1) && (*nb % 10) == *box)
		return (TRUE);
	else if (nb_len == scope_len && (*nb / power10(nb_len - 1) == *box))
		return (TRUE);
	else if ((nb_len > scope_len && scope_len > 1)
	&& ((*nb / power10(scope_len - 1) % 10)) == *box)
		return (TRUE);
	else if (nb_len < scope_len && *box == 0)
		return (TRUE);
	else
		return (FALSE);		
}

t_bool	scope_check(t_stack *stack, int *scope, int *box)
{
	t_list_ps	*tmp;
	int			val_tmp;

	if (!stack)
		return (ERROR);
	if (stack->top_item)
		tmp = stack->top_item;
	while (tmp)
	{
		if (tmp->value < 0)
			val_tmp = -tmp->value;
		else
			val_tmp = tmp->value;
		if (scope_validation(&val_tmp, scope, box) == TRUE)
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
		if (scope_validation(&tmp->value, scope, box) == TRUE)
			return (distance);
		distance ++;
	}
	return (0);
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

void	radix(t_stack *stack, t_stack *stack2, int *scope)
{
	int 	box_i;
	int		scope_len;
	t_stack	**stack_group;

	stack_group = NULL;
	scope_len = create_radix_env(stack_group, stack, stack2, scope);
	if (!stack_group)
		return ;
	box_i = 0;
	while (stack && stack->top_item && box_i < 10 
	&& stack->last_item && scope_len <= get_maxlen(stack))
	{
		if (scope_check(stack, scope, &box_i) == FALSE)
			box_i ++;
		if (scope_validation(&stack->top_item->value, scope, &box_i)
		== TRUE)
			push_b(stack, stack2);
		else if (stack->top_item->next &&
		scope_validation(&stack->top_item->next->value, scope, &box_i)== TRUE)
			rotate_a(stack, FALSE);
		else if (scope_validation(&stack->last_item->value, scope, &box_i)
		== TRUE)
			reverse_r_a(stack, FALSE);
		else
			while (dist_from_top(stack, scope, &box_i) > 0)
				if (dist_from_top(stack, scope, &box_i) < (stack->size / 2))
					rotate_a(stack, FALSE);
				else
					reverse_r_a(stack, FALSE);
	}
	free(stack_group);
}