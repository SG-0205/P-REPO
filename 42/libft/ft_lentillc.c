/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lentillc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:04:36 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/29 18:11:43 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lentillc(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i ++;
	return (i);
}