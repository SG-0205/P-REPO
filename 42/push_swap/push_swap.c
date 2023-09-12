/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:36:40 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/12 19:09:18 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	
	args_checker(argc, argv), stack_init(&a, &b, argc, argv);
	// ft_("%d", end_check(&a, 'a', swap_a));
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