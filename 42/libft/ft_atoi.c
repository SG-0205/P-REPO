/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:44:27 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/04/17 18:04:55 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	min_count;
	int	max_count;

	i = 0;
	res = 0;
	min_count = 0;
	max_count = 0;
	while ((nptr[i] >= '0' && nptr[i] <= '9') || (nptr[i] >= 1 && nptr[i] <= 31)
		|| (nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '+')
			max_count ++;
		if (nptr[i] == '-')
			min_count++;
		if (nptr[i] >= '0' && nptr[i] <= '9')
			res = res * 10 + (nptr[i] - 48);
		i ++;
	}
	if (min_count > 1 || max_count > 1 || max_count + min_count > 1)
		return (0);
	if (min_count % 2 == 1)
		return (res * -1);
	return (res);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (0);
// 	printf("%d\t ft_atoi\n", ft_atoi(argv[1]));
// 	printf("%d\t atoi", atoi(argv[1]));
// 	return (0);
// }