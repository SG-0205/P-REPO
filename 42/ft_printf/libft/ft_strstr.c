/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:05:25 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/20 22:39:49 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*ptr_needle;

	ptr_needle = (char *)haystack;
	if (needle == NULL || needle[0] == 0)
		return (ptr_needle);
	i = 0;
	j = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i] == needle[j])
		{
			j ++;
			i ++;
			if (needle[j] == '\0')
			{
				ptr_needle = (char *)&haystack[i - j];
				return (ptr_needle);
			}
		}
		i ++;
	}
	return (NULL);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 3)
// 		return (0);
// 	printf("%s", ft_strstr(argv[1], argv[2]));
// 	return (0);
// }