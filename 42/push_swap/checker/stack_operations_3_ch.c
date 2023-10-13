/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3_ch.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:54:24 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/13 16:16:01 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_both_ch(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	swap_a_ch(a);
	swap_b_ch(b);
}

void	rotate_all_ch(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	rotate_a_ch(a);
	rotate_b_ch(b);
}

void	reverse_r_all_ch(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size == 0 || b->size == 0)
		return ;
	reverse_r_a_ch(a);
	reverse_r_b_ch(b);
}
