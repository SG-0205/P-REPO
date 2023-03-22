/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:12:59 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/22 13:41:16 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	new_str = ft_strnew(len);
	if (!new_str)
		return (NULL);
	while (i < len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	return (new_str);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 4)
// 		return (1);
// 	printf("%s", ft_strsub(argv[1], (unsigned int)ft_atoi(argv[2]),
// (size_t)ft_atoi(argv[3])));
// 	return (0);
// }