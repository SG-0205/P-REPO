/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medians.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:47:11 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/07 20:47:26 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_ps *get_median_item(t_stack *stack, int pivot_location)
{
	int			i;
	t_list_ps	*tmp;

	i = -1;
	tmp = stack->top_item;
	while (++i < pivot_location)
		tmp = tmp->next;
	ft_printf("\nValeur médiane : %d", tmp->value);
	return (tmp);
}

int	get_median(t_stack *stack)
{
	int			place;
	t_list_ps	*tmp;

	place = -1;
	tmp = stack->top_item;
	while (++place < (stack->size / 2))
		tmp = tmp->next;
	ft_printf("Médiane : %d\n", place);
	return (place);
}

int	medianof3_pivot(t_stack *a)
{
	int	pivot;
	int	*values;
	int	i;
	int j;
	
	i = 0;
	pivot = 0;
	j = 0;
	values = (int *)malloc(3 * sizeof (int));
	values[0] = a->top_item->value;
	values[1] = get_median(a);
	values[2] = a->last_item->value;
	while (i < 3)
	{
		if (values[i] < values[j])
			pivot = values[j];
		i ++;
	}
	free(values);
	return (pivot);
}