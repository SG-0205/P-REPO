/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:59:15 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/17 20:28:48 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ptr_dest;
	const char	*ptr_src;
	char		*ptr_swap;

	ptr_src = src;
	ptr_dest = dest;
	ptr_swap = (char *) malloc((n + 1) * sizeof(char));
	i = 0;
	while (i < n && i ++)
		ptr_swap[i] = ptr_src[i];
	i = 0;
	while (i < n && i ++)
		ptr_dest[i] = ptr_swap[i];
	free(ptr_swap);
	return (ptr_dest);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return (666);
	int	*nb_stock;
	char *ch_stock;
	int	*nb_stock2;
	char *ch_stock2;
	int i = 0;
	ft_memmove(nb_stock, atoi(argv[1]), argv[2]);
	ft_memmove(ch_stock, argv[1], argv[2]);
	memmove(nb_stock2, atoi(argv[1]), argv[2]);
	memmove(ch_stock2, argv[1], argv[2]);
	while (i )	
}
