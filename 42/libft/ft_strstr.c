/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:05:25 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/10 16:05:53 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find == NULL || to_find[0] == 0)
		return (str);
	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] == to_find[j])
		{
			j ++;
			i ++;
			if (to_find[j] == '\0')
				return (&str[i - j]);
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