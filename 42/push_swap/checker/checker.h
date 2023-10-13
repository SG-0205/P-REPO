/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 01:55:02 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/13 16:49:43 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

typedef struct s_command
{
	char				*command;
	struct s_command	*next;
}t_command;

t_command	*ft_lstnew_ch(char *command);
t_command	*ft_lstlast_ch(t_command *lst);
void		ft_lstdelone_ch(t_command *lst);
void		ft_lstclear_ch(t_command **lst);
void		ft_lstadd_back_ch(t_command **lst, t_command *new);

void		commands_checker(t_command *commands, t_stack *a, t_stack *b);
void		rotate_check(t_command *command, t_stack *a, t_stack *b);
void		swap_check(t_command *command, t_stack *a, t_stack *b);
t_bool		exec_cmds(t_command *cmd_list, t_stack *a, t_stack *b);

void		swap_a_ch(t_stack *stack);
void		swap_b_ch(t_stack *stack);
void		swap_both_ch(t_stack *a, t_stack *b);
void		push_a_ch(t_stack *a, t_stack *b);
void		push_b_ch(t_stack *a, t_stack *b);
void		rotate_b_ch(t_stack *b);
void		rotate_a_ch(t_stack *a);
void		rotate_all_ch(t_stack *a, t_stack *b);
void		reverse_r_a_ch(t_stack *a);
void		reverse_r_b_ch(t_stack *b);
void		reverse_r_all_ch(t_stack *a, t_stack *b);

#endif
