/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management_high.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:55:53 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/05 17:55:19 by sgoldenb         ###   ########.fr       */
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

void	ft_lstiter_ps(t_list_ps *lst, void (*f)(int))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->value);
		lst = lst->next;
	}
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