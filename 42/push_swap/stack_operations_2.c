/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:43:30 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/06 19:53:45 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_stack *b)
{
	t_list_ps	*tmp;

	if (!b)
		return;
	tmp = b->top_item;
	b->top_item = b->top_item->next;
	tmp->next = NULL;
	ft_lstadd_back_ps(&b->top_item, tmp);
	b->last_item = ft_lstlast_ps(b->top_item);
	ft_putendl("rb");
	printstack(b, 'b');
}