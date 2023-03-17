/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:58:40 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/17 14:58:10 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char		*ptr_dest;
	const char	*ptr_src;

	ptr_src = src;
	ptr_dest = dest;
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (ptr_dest);
}

// int main(void)
// {
// 	char	zero[]="0000";
// 	char	zero2[]="0000";
// 	char	test[]="1234";
// 	char	test2[]="1234";

// 	ft_memcpy(test, zero, 5);
// 	memcpy(test2, zero2, 5);
// 		printf("%s", test);
// 	printf("\n");
// 		printf("%s", test2);
// 	return (0);
// }