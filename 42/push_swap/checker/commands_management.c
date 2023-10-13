/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:40:18 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/13 16:48:57 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_command	*ft_lstnew_ch(char *command)
{
	t_command	*new;

	if (!command)
		return (NULL);
	new = (t_command *)malloc(sizeof(t_command));
	if (!new)
		return (NULL);
	new->command = ft_strdup(command);
	if (!new->command)
		return (NULL);
	free(command);
	new->next = NULL;
	return (new);
}

t_command	*ft_lstlast_ch(t_command *lst)
{
	t_command	*tmp;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstdelone_ch(t_command *lst)
{
	if (!lst)
		return ;
	free(lst->command);
	free(lst);
}

void	ft_lstclear_ch(t_command **lst)
{
	t_command	*tmp;

	if (lst && *lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone_ch(*lst);
			*lst = tmp;
		}
	}
}

void	ft_lstadd_back_ch(t_command **lst, t_command *new)
{
	t_command	*tmp;

	if (!new)
		return ;
	else if (!lst || !(*lst))
		*lst = new;
	else
	{
		tmp = *lst;
		tmp = ft_lstlast_ch(*lst);
		tmp->next = new;
		return ;
	}
}
