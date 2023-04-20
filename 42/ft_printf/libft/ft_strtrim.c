/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:56:21 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/22 15:16:53 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

char	*ft_strtrim(const char *s)
{
	char	*new_str;
	char	*wsp;
	size_t	s_end;

	wsp = " ,\n\t";
	s_end = ft_strlen(s);
	new_str = ft_strnew(s_end);
	new_str = ft_strcpy(new_str, s);
	if (!new_str)
		return (NULL);
	if (ft_cisar(s[0], wsp) == 0 && ft_cisar(s[s_end - 1], wsp) == 0)
		return (new_str);
	if (ft_cisar(s[0], wsp) == 1)
	{
		new_str = ft_strsub(s, 1, (s_end - 1));
		s_end -= 1;
	}
	if (ft_cisar(s[s_end], wsp) == 1)
		new_str[s_end - 1] = 0;
	return (new_str);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (1);
// 	printf("%s\t<Sans whitespaces\n", ft_strtrim(argv[1]));
// 	return (0);
// }