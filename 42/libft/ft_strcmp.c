/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:59:52 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/20 22:17:14 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 3)
// 		return (0);
// 	printf("%d", ft_strcmp(argv[1], argv[2]));
// 	return (0);
// }