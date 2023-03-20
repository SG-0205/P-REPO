/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:59:15 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/20 11:54:43 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ptr_dst;
	const char	*ptr_src;
	char		*ptr_swap;

	ptr_src = (const char *)src;
	ptr_dst = (char *)dst;
	ptr_swap = (char *) malloc((n) * sizeof(char));
	ft_bzero(ptr_swap, n);
	i = 0;
	while (i++, i < n)
		ptr_swap[i] = ptr_src[i];
	i = 0;
	while (i ++, i < n)
		ptr_dst[i] = ptr_swap[i];
	free(ptr_swap);
	return (dst);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return (666);
	int	nb_stock[100];
	char ch_stock[100];
	int	nb_stock2[100];
	char ch_stock2[100];
	int i = 0;
	ft_memmove(nb_stock, argv[1], atoi(argv[2]));
	ft_memmove(ch_stock, argv[1], atoi(argv[2]));
	memmove(nb_stock2, argv[1], atoi(argv[2]));
	memmove(ch_stock2, argv[1], atoi(argv[2]));
	printf("int:ft_memmove\n");
	while (i++, i < atoi(argv[2]))
		printf("%d",nb_stock[i]);
	printf("\n");
	i = 0;
	printf("char:ft_memmove\n");
	while (i++, i < atoi(argv[2]))
		printf("%c",ch_stock[i]);
	printf("\n");
	i = 0;
	printf("int:memmove\n");
	while (i++, i < atoi(argv[2]))
		printf("%d",nb_stock2[i]);
	printf("\n");
	i = 0;
	printf("char:memmove\n");
	while (i++, i < atoi(argv[2]))
		printf("%c",ch_stock2[i]);
	printf("\n");
	return (0);
}
