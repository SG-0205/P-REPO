/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:28:28 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/04 18:17:24 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_list_ps{
	int			value;
	t_list_ps	*next;
} t_list_ps;

typedef struct s_stack{
	t_list_ps	*top_item;
	int		size;
}	t_stack;

t_list_ps	*ft_lstnew_ps(int value);
void		ft_lstdelone_ps(t_list_ps *lst, void (*del)(int));
t_list_ps	*ft_lstlast_ps(t_list_ps *lst);
void		ft_lstclear_ps(t_list_ps **lst, void (*del)(int));
void		ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new);
void	ft_lstadd_front_ps(t_list_ps **lst, t_list_ps *new);
void		ft_lstiter_ps(t_list_ps *lst, void (*f)(int));
t_list_ps	*ft_lstmap_ps(t_list_ps *lst, void *(*f)(int), void (*del)(int));


#endif