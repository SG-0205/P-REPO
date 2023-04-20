/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:49:51 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/04/05 10:32:55 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_initarray(char **array, const char *s, char c)
{
	t_bool	is_init;
	size_t	i;
	size_t	j;
	size_t	nb_wrds;

	is_init = 0;
	j = 0;
	i = 0;
	nb_wrds = ft_countwords(s, c);
	while (s[j] && i < nb_wrds)
	{
		if (s[j] == c)
			is_init = FALSE;
		else if (s[j] != c && is_init == FALSE)
		{
			array[i] = ft_strnew(ft_lentillc(&(s[j]), c));
			is_init = TRUE;
			i ++;
		}
		j ++;
	}
}

void	ft_fillarray(char **array, const char *s, char c)
{
	t_bool	start_cpy;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	start_cpy = 0;
	while (s[j])
	{
		if (s[j] == c)
			start_cpy = FALSE;
		else if (s[j] != c && start_cpy == FALSE)
		{
			array[i] = ft_strncpy(array[i], &(s[j]), ft_lentillc(&(s[j]), c));
			start_cpy = TRUE;
			i ++;
		}
		j ++;
	}
}

char	**ft_strsplit(const char *s, char c)
{
	char	**array;

	array = (char **)malloc(ft_countwords(s, c) * sizeof(char *));
	ft_initarray(array, s, c);
	ft_fillarray(array, s, c);
	return (array);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	char **array = ft_strsplit(argv[1], argv[2][0]);
	printf("%s\t%s\t%s",array[0],  array[1], array[2]);
	return (0);
}
