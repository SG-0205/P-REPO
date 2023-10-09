/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:54:24 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/09 20:20:44 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	swap_a(a, TRUE);
	swap_b(b, TRUE);
}

void	rotate_all(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	rotate_a(a, TRUE);
	rotate_b(b, TRUE);
}

void	reverse_r_all(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size == 0 || b->size == 0)
		return ;
	reverse_r_a(a, TRUE);
	reverse_r_b(b, TRUE);
}
