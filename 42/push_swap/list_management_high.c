/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management_high.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:55:53 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/12 16:33:02 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_ps	*ft_lstmap_ps(t_list_ps *lst, int (*f)(int))
{
	t_list_ps	*begin;
	t_list_ps	*work;

	if (lst != NULL && f != NULL)
	{
		begin = ft_lstnew_ps(f(lst->value));
		if (!begin)
			return (NULL);
		work = begin;
		while (lst->next)
		{
			lst = lst->next;
			if (work == NULL)
			{
				ft_lstclear_ps(&begin);
				return (NULL);
			}
			work->next = ft_lstnew_ps(f(lst->value));
			work = work->next;
		}
		return (begin);
	}
	return (NULL);
}

t_list_ps	*ft_lstbflast(t_list_ps *top)
{
	t_list_ps	*tmp;
	
	if (!top)
		return (NULL);
	tmp = top;
	while (tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstclear_ps(t_list_ps **lst)
{
	t_list_ps	*tmp;

	if (lst && *lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone_ps(*lst);
			*lst = tmp;
		}
	}
}

void	ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new)
{
	t_list_ps	*tmp;

	if (!new)
		return ;
	else if (!lst || !(*lst))
		*lst = new;
	else
	{
		tmp = *lst;
		tmp = ft_lstlast_ps(*lst);
		tmp->next = new;
		return ;
	}
}

void	ft_lstadd_front_ps(t_list_ps **lst, t_list_ps *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}