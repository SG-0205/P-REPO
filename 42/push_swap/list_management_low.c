/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management_low.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:55:53 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/04 18:19:41 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_ps	*ft_lstnew_ps(int value)
{
	t_list_ps	*new;

	new = (t_list_ps *)malloc(sizeof(t_list_ps));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_list_ps	*ft_lstlast_ps(t_list_ps *lst)
{
	t_list_ps	*tmp;

	if (!lst)
		return (NULL);
	if (!(lst->next))
		return (lst);
	tmp = lst->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstdelone_ps(t_list_ps *lst, void (*del)(int))
{
	if (!lst || !del)
		return ;
	del(lst->value);
	free(lst);
}
