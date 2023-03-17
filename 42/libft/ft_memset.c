/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:44:44 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/17 12:22:46 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (str[i] && i < n)
	{
		str[i] = c;
		i ++;
	}
	return (s);
}

// int main(void)
// {
// 	char str[]="12456666";
// 	ft_memset(str, '8', 5);
// 	printf("%s", str);
// 	return (0);
// }