/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:06:27 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/21 21:58:09 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strequ(const char *s1, const char *s2)
{
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	else
		return (0);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	printf("%d\t", NULL); //2BDONE
	printf("%d\tft_strcmp\n", strcmp(argv[1], argv[2]));
	printf("%d\tft_streq\n", ft_strequ(argv[1], argv[2]));
	return (0);
}