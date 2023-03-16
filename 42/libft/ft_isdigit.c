/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:51:15 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/16 21:22:19 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>
int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (2048);
	else
		return (0);
}

// int main (int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (666);
// 	printf("%d\t ft_isalpha\n", ft_isdigit(argv[1][0]));
// 	printf("%d\t isalpha", isdigit(argv[1][0]));
// 	return (0);
// }