/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:36:40 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/07 10:54:41 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printstack(t_stack *stack, char name)
{
	t_list_ps	*next;
	
	ft_printf("Stack %c\n", name);
	next = stack->top_item;
	while (next)
	{
		ft_printf("%d\n", next->value);
		next = next->next;
	}
	ft_printf("Taille de la stack : %d\n", stack->size);
	if (stack->top_item)
		ft_printf("1ere valeur : %d\n", stack->top_item->value);
	if (stack->last_item)
		ft_printf("Derniere valeur : %d\n\n", stack->last_item->value);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	args_checker(argc, argv), stack_init(&a, &b, argc, argv);
	quick_sort(&a, &b);
	// medianof3_pivot(&a);
	// push_b(&a, &b);
	// printstack(&a, 'a');
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