/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:03:59 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/16 20:49:55 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (to_find == NULL || to_find[0] == 0)
		return ((char *)str);
	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] == to_find[j] && i <= len)
		{
			j ++;
			i ++;
			if (to_find[j] == '\0' || j == len)
				return ((char *)&str[i - j]);
		}
		i ++;
	}
	return (NULL);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 4)
// 		return (0);
// 	printf("%s", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
// 	return (0);
// }