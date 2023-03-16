/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:03:52 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/16 20:40:32 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t sz)
{
	size_t	i;

	i = 0;
	while (src[i] && i < sz)
	{
		dest[i] = src[i];
		i ++;
	}
	while (i < sz)
		dest[i++] = '\0';
	return (dest);
}

// int main()
// {
// 	char src[] = "123456789";
// 	char *dest;
// 	int i = 0;
// 	while(src[i])
// 		i++;
// 	dest = (char *)malloc(i * sizeof(char) + 1);
// 	dest = ft_strncpy(dest, src, 15);
// 	printf("%s", dest);
// 	free(dest);
// 	return (0);
// }