/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:28:28 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/07 10:33:14 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_list_ps
{
	int					value;
	struct s_list_ps	*next;
}t_list_ps;

typedef struct s_stack
{
	t_list_ps	*top_item;
	t_list_ps	*last_item;
	int			size;
}	t_stack;

void		error(void);
void		stack_init(t_stack *a, t_stack *b, int argc, char **argv);
void		doublon_check(int argc, char **args);
void		args_checker(int argc, char **args);
void		printstack(t_stack *stack, char name);

void		swap(t_stack *stack, t_bool isA);
void		swap_both(t_stack *a, t_stack *b);
void		push_a(t_stack *a, t_stack *b);
void		push_b(t_stack *a, t_stack *b);
void		rotate_a(t_stack *a, t_bool rr);
void		rotate_b(t_stack *b, t_bool rr);
void		reverse_r_a(t_stack *a, t_bool rrr);

int			get_median(t_stack *stack);
int			medianof3_pivot(t_stack *a);
void		quick_sort(t_stack *a, t_stack *b);

t_list_ps	*ft_lstnew_ps(int value);
void		ft_lstdelone_ps(t_list_ps *lst);
t_list_ps	*ft_lstlast_ps(t_list_ps *lst);
void		ft_lstclear_ps(t_list_ps **lst);
void		ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new);
void		ft_lstadd_front_ps(t_list_ps **lst, t_list_ps *new);
t_list_ps	*ft_lstbflast(t_list_ps *top);
t_list_ps	*ft_lstmap_ps(t_list_ps *lst, int (*f)(int));


#endif