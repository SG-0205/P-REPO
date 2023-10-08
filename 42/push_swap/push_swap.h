/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:28:28 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/09 00:10:44 by sgoldenb         ###   ########.fr       */
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
void		stack_init_split(t_stack *a, t_stack *b, char **argv);
void		doublon_check(int argc, char **args);
void		args_checker(int argc, char **args);
void		args_checker_split(int argc, char **args);
int			free_all(t_stack *a, t_stack *b);
void		free_split(char **splitted_args);
t_bool		is_max(t_stack *stack);
int			get_maxval(t_stack *stack);
void		printstack(t_stack *stack, char name);

void		swap_a(t_stack *stack, t_bool ss);
void		swap_b(t_stack *stack, t_bool ss);
void		swap_both(t_stack *a, t_stack *b);
void		push_a(t_stack *a, t_stack *b);
void		push_b(t_stack *a, t_stack *b);
void		rotate_a(t_stack *a, t_bool rr);
void		rotate_b(t_stack *b, t_bool rr);
void		reverse_r_a(t_stack *a, t_bool rrr);
void		reverse_r_b(t_stack *b, t_bool rrr);

int			get_median(t_stack *stack);
t_list_ps 	*get_median_item(t_stack *stack, int pivot_location);
int			medianof3_pivot(t_stack *a);
void		quick_sort_a(t_stack *a, t_stack *b);
void		quick_sort_b(t_stack *a, t_stack *b, char from_name);
t_bool		sort_check(t_stack *a);
t_bool		rev_sort_check(t_stack *a);
t_bool		check_pivot(t_stack *stack, int *pivot_value);
t_bool		end_check(t_stack *stack, char name, void (*swap)(t_stack *, t_bool));
void		sort_three_rev(t_stack *stack, void (*swap)(t_stack *, t_bool),
void (*reverse_r)(t_stack *, t_bool));
void		sort_three(t_stack *stack, void (*swap)(t_stack *, t_bool),
void (*reverse_r)(t_stack *, t_bool));
void		sort5_rev(t_stack *a, t_stack *b);
void		order_b(t_stack *b);
void		merge(t_stack *a, t_stack *b);
t_bool		check_rest(t_list_ps *start);
void		neg_sort(t_stack *a, t_stack *b);
t_bool		neg_check(t_stack *stack);
size_t		neg_count(t_stack *stack);
int			get_maxlen(t_stack *stack);
int			get_int(int value, int order);
int			power10(int power);
t_bool		scope_validation(int *nb, int *scope, int *box);
void		ft_intlen2(long int n, int *len);
void		radix(t_stack *a, t_stack *b);
void		radix_pos(t_stack *a, t_stack *b);
void		radix_neg(t_stack *a, t_stack *b);
void		radix_sort(t_stack *stack, t_stack *stack2, int *scope);
void		final_sort(t_stack *a, t_stack *b);
t_bool		scope_check(t_stack *stack, int *mask);

t_list_ps	*ft_lstnew_ps(int value);
void		ft_lstdelone_ps(t_list_ps *lst);
t_list_ps	*ft_lstlast_ps(t_list_ps *lst);
void		ft_lstclear_ps(t_list_ps **lst);
void		ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new);
void		ft_lstadd_front_ps(t_list_ps **lst, t_list_ps *new);
t_list_ps	*ft_lstbflast(t_list_ps *top);
t_list_ps	*ft_lstmap_ps(t_list_ps *lst, int (*f)(int));


#endif