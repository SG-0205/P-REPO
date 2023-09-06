/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:43:30 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/06 19:53:12 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, t_bool isA)
{	
	t_list_ps	*tmp;
	
	if (stack->size < 2 || !stack)
		return;
	tmp = stack->top_item;
	stack->top_item = tmp->next;
	tmp->next = stack->top_item->next;
	stack->top_item->next = tmp;
	printstack(stack, 'a');
	if (isA == 3)
		ft_putendl("ss");
	else if (isA == TRUE)
		ft_putendl("sa");
	else if (isA == FALSE)
		ft_putendl("sb");
}

void	swap_both(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return;
	swap(a, 3);
	swap(b, 3);
}

void	push_a(t_stack *a, t_stack *b)
{
	t_list_ps	*tmp;

	if (!b || !a || b->size == 0)
		return;
	tmp = b->top_item;
	b->top_item = b->top_item->next;
	tmp->next = a->top_item;
	b->size --;
	a->top_item = tmp;
	a->size ++;
	a->last_item = ft_lstlast_ps(a->top_item);
	ft_putendl("pa");
	printstack(a, 'a');
}

void	push_b(t_stack *a, t_stack *b)
{
	t_list_ps	*tmp;

	if (!b || !a || a->size == 0)
		return;
	tmp = a->top_item;
	a->top_item = a->top_item->next;
	tmp->next = b->top_item;
	a->size --;
	b->top_item = tmp;
	b->size ++;
	b->last_item = ft_lstlast_ps(b->top_item);
	ft_putendl("pb");
	printstack(b, 'b');
}

void	rotate_a(t_stack *a)
{
	t_list_ps	*tmp;

	if (!a)
		return;
	tmp = a->top_item;
	a->top_item = a->top_item->next;
	tmp->next = NULL;
	ft_lstadd_back_ps(&a->top_item, tmp);
	a->last_item = ft_lstlast_ps(a->top_item);
	ft_putendl("ra");
	printstack(a, 'a');
}