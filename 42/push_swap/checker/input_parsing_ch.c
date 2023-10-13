/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_ch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:26:30 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/13 17:31:51 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	free_all(t_stack *a, t_stack *b)
{
	if (!a && !b)
		return (0);
	if (a && a->top_item)
		(ft_lstclear_ps(&a->top_item), a->last_item = NULL);
	if (b && b->top_item)
		ft_lstclear_ps(&b->top_item);
	if (a)
		free(a);
	if (b)
		free(b);
	return (TRUE);
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
