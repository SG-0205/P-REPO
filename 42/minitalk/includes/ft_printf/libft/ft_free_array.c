/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 02:23:25 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/11/14 02:52:14 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_array_len(char	**array)
{
	size_t	len;

	len = 0;
	while (array[len])
		len ++;
	return (len);
}

void	ft_free_array(char **array)
{
	int	len;

	if (!array)
		return ;
	len = (int)ft_array_len(array);
	while (--len >= 0)
		free(array[len]);
	free(array);
}