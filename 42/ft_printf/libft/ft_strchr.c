/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:59:19 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/20 22:17:10 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int			i;
	int			total_len;
	const char	*c_is_here;

	total_len = 0;
	c_is_here = NULL;
	while (s[total_len])
		total_len ++;
	total_len += 1;
	i = 0;
	while (i <= total_len)
	{
		if (s[i] == c)
			c_is_here = &s[i];
		i ++;
	}
	return ((char *)c_is_here);
}

// int main()
// {
// 	const char	str[]="0123456789";
// 	char	c='7';
// 	char	*p_str;

// 	p_str = ft_strchr(str, c);
// 	printf("%s", p_str);
// 	if (p_str[0] == '\0')
// 		printf("Much Waw");
// 	return (0);
// }