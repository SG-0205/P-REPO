/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:17:42 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/20 22:16:26 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>
#include "libft.h"

int	ft_isascii(int c)
{
	if (c <= 127 && c >= 0)
		return (16384);
	else
		return (0);
}

// int main (int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (666);
// 	printf("%d\t ft_isascii\n", ft_isascii(argv[1][0]));
// 	printf("%d\t isascii", isprint(argv[1][0]));
// 	return (0);
// }