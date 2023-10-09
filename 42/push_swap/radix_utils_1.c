/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:48:31 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/09 20:28:07 by sgoldenb         ###   ########.fr       */
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
