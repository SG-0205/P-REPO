/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:36:40 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/13 14:56:04 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	if (a->size > 0 && a->top_item)
		ft_lstclear_ps(&a->top_item);
	if (b->size > 0 && b->top_item)
		ft_lstclear_ps(&b->top_item);
}

int	sort3_return(t_stack *a, t_stack *b)
{
	if (!a || !b)
		error();
	sort_three(a, swap_a, reverse_r_a);
	free_all(a, b);
	return (0);
}

int	sort5_return(t_stack *a, t_stack *b)
{
	if (!a || !b)
		error();
	push_b(a, b), push_b(a, b);
	sort_three(a, swap_a, reverse_r_a);
	while (b->size > 0)
	{
		push_a(a, b);
		if (a->top_item->value > a->last_item->value)
			rotate_a(a, FALSE);
		else if (a->top_item->value > a->top_item->next->value)
			swap_a(a, FALSE);
	}
	if (sort_check(a) == TRUE)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	
	args_checker(argc, argv), stack_init(&a, &b, argc, argv);
	if (argc == 4)
		return (sort3_return(&a, &b));
	if (argc == 6)
		return (sort5_return(&a, &b));
	quick_sort_a(&a, &b);
	// order_b(&a);
	if (sort_check(&a) == TRUE && b.size == 0)
		ft_printf("\nOK\n");
	else
		ft_printf("\nKO\n");
	// quick_sort_a(&a, &b, 'a');
	// quick_sort_b(&a, &b, 'a');
	// quick_sort_a(&a, &b, 'a');
	// quick_sort_a(&a, &b, 'a');
	// quick_sort_a(&a, &b, 'a');
	// quick_sort_a(&a, &b, 'a');
	// quick_sort_a(&a, &b, 'a');

	// printstack(&a, 'a');
	// printstack(&b, 'b');
	// rotate_a(&a, FALSE);
	// ft_("%d", sort_check(&a));
	// printstack(&a, 'a');
	// printstack(&b, 'b');
	// medianof3_pivot(&a);
	// push_b(&a, &b);
	// push_b(&a, &b);
	// push_b(&a, &b);
	// push_b(&a, &b);
	// printstack(&a, 'a');
	// printstack(&b, 'b');
	// push_b(&a, &b);
	// push_b(&a, &b);
	// push_a(&a, &b);
	// rotate_a(&a, FALSE);
	// rotate_a(&a, FALSE);
	// rotate_a(&a, FALSE);
	// reverse_r_a(&a, FALSE);
	// reverse_r_a(&a, FALSE);
	// reverse_r_a(&a, FALSE);
	// printstack(&a, 'a');
	// ft_lstbflast(a.top_item);
	// rotate_b(&b, FALSE);
	// swap(&a, TRUE);
	// swap(&a, TRUE);
	return (0);
}