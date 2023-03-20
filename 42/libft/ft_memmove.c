/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:59:15 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/20 22:40:41 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*ptr_dst;
	const char	*ptr_src;
	char		*ptr_swap;

	ptr_src = (const char *)src;
	ptr_dst = (char *)dst;
	ptr_swap = (char *) malloc((n) * sizeof(char));
	ft_bzero(ptr_swap, n);
	ft_memcpy(ptr_swap, ptr_src, n);
	ft_memcpy(ptr_dst, ptr_swap, n);
	free(ptr_swap);
	return (dst);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 3)
// 		return (666);

// 	int	*nb_stock;
// 	char *ch_stock;
// 	int	*nb_stock2;
// 	char *ch_stock2;

// 	nb_stock = (int *)malloc(ft_strlen(argv[1]) * sizeof(int));
// 	ch_stock = (char *)malloc(ft_strlen(argv[1]) * sizeof(char) + 1);
// 	nb_stock2 = (int *)malloc(ft_strlen(argv[1]) * sizeof(int));
// 	ch_stock2 = (char *)malloc(ft_strlen(argv[1]) * sizeof(char) + 1);

// 	ft_memmove(nb_stock, argv[1], atoi(argv[2]));
// 	ft_memmove(ch_stock, argv[1], atoi(argv[2]));
// 	memmove(nb_stock2, argv[1], atoi(argv[2]));
// 	memmove(ch_stock2, argv[1], atoi(argv[2]));

// 	int i = 0;
// 	printf("int:ft_memmove\n");
// 	while (i++, i < atoi(argv[2]))
// 		printf("%d",nb_stock[i]);
// 	printf("\n");

// 	i = 0;
// 	printf("char:ft_memmove\n");
// 	while (i++, i < atoi(argv[2]))
// 		printf("%c",ch_stock[i]);
// 	printf("\n");

// 	i = 0;
// 	printf("int:memmove\n");
// 	while (i++, i < atoi(argv[2]))
// 		printf("%d",nb_stock2[i]);
// 	printf("\n");

// 	i = 0;
// 	printf("char:memmove\n");
// 	while (i++, i < atoi(argv[2]))
// 		printf("%c",ch_stock2[i]);
// 	printf("\n");

// 	return (0);
// }
