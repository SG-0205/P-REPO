/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 01:55:02 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/13 02:58:42 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHEKER_H

# include "../push_swap.h"

typedef struct s_command
{
	char		*command;
	struct s_command	*next;
}t_command;

t_command	*ft_lstnew_ch(char *command);
t_command	*ft_lstlast_ch(t_command *lst);
void		ft_lstdelone_ch(t_command *lst);
void		ft_lstclear_ch(t_command **lst);
void		ft_lstadd_back_ch(t_command **lst, t_command *new);

#endif