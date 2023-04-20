/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:23:38 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/24 16:49:00 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			(*f)(i, s + i);
			i++;
		}
	}
}

// void	test_ft_upper(char *c)
// {
// 	*c = *c - 32;
// }

// int main(void)
// {
// 	char	s[] = "abcdef";
// 	void	*ptr_f = &test_ft_upper;
// 	ft_striter(s, ptr_f);
// 	printf("%s\t<Doit être en MAJ", s);
// 	return (0);
// }