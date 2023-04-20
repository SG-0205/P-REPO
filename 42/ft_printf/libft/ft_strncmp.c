/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:02:59 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/22 13:09:30 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 4)
// 		return (0);
// 	printf("%d\tstrncmp\n", strncmp(argv[1], argv[2], ft_atoi(argv[3])));
// 	printf("%d \tft_strncmp\n", ft_strncmp(argv[1], argv[2], ft_atoi(argv[3])));
// 	return (0);
// }