/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:08:15 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/21 20:54:55 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	ptr = malloc(size * sizeof(char));
	ft_bzero(ptr, size);
	return (ptr);
}

// int main(void)
// {
// 	char *test;

// 	test = ft_memalloc(5);
// 	ft_memset(test, 'U', 5);
// 	printf("%s", test);
// 	return 0;
// }