/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:41:17 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/18 20:51:57 by sgoldenb         ###   ########.fr       */
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
	if ((scope_len == 1) && (*nb % 10 == *box))
		return (TRUE);
	else if (scope_len > 1 && nb_len == scope_len && (*nb / power10(scope_len - 1) == *box))
		return (TRUE);
	else if (scope_len > 1 && (nb_len > scope_len)
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
	// ft_printf("SCOPE_CHECK\n");
	while (tmp)
	{
		// printstack(stack, 'a');
		if (tmp->value < 0)
			val_tmp = -tmp->value;
		else
			val_tmp = tmp->value;
		// ft_printf("VALIDATING\n");
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
	while (scope_validation(&tmp->value, scope, box) == FALSE)
	{
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

void	radix_sort(t_stack *stack, t_stack *stack2, int *scope)
{
	int 	box_i;
	int		scope_len;
	t_stack	**stack_group;

	stack_group = NULL;
	scope_len = create_radix_env(stack_group, stack, stack2, scope);
	box_i = 0;
	while (box_i < 10 && scope_len <= get_maxlen(stack))
	{
		// ft_printf("\nBOX_I : %d\n", box_i);
		if (box_i == 10)
			break;
		if (scope_check(stack, scope, &box_i) == FALSE)
			box_i ++;
		else if (scope_validation(&stack->top_item->value, scope, &box_i)
		== TRUE)
			push_b(stack, stack2);
		// else if (stack->size < 4)
		// 	swap_a(stack, FALSE);
		else if (dist_from_top(stack, scope, &box_i) <= (stack->size / 2))
			rotate_a(stack, FALSE);
		else if (dist_from_top(stack, scope, &box_i) > (stack->size / 2))
			reverse_r_a(stack, FALSE);
	}
	free(stack_group);
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

void	radix(t_stack *a, t_stack *b, int *scope)
{
	int	scope_len;

	scope_len = 0;
	ft_intlen2(*scope, &scope_len);
	if (!a || !b)
		return ;
	radix_sort(a, b, scope);
	// printstack(a, 'a'), printstack(b, 'b');
	while (b->top_item)
		push_a(a, b);
	// printstack(a, 'a'), printstack(b, 'b');
}