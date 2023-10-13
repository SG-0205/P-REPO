/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking_ch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:39:37 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/13 17:30:35 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_bool	args_checker_split(int argc, char **args)
{
	int	i;
	int	j;
	int	int_len;

	i = 0;
	while (i < (int)split_len(args))
	{
		j = 0;
		int_len = 0;
		ft_intlen2(ft_atoi(args[i]), &int_len);
		if (ft_atoi(args[i]) > __INT_MAX__
			|| ft_atoi(args[i]) < (__INT_MAX__ * -1) + 1
			|| ft_strlen(args[i]) != (size_t)int_len)
			return (FALSE);
		while (args[i][j])
		{
			if (ft_isdigit(args[i][j]) == 0 && args[i][j] != '-')
				return (FALSE);
			j ++;
		}
		i ++;
	}
	return (doublon_check_split(argc, args));
}

t_bool	args_checker(int argc, char **args)
{
	int	i;
	int	j;
	int	int_len;

	i = 1;
	if (argc == 1)
		error();
	while (i < argc)
	{
		j = 0;
		int_len = 0;
		ft_intlen2(ft_atoi(args[i]), &int_len);
		if (ft_atoi(args[i]) > __INT_MAX__
			|| ft_atoi(args[i]) < (__INT_MAX__ * -1) + 1
			|| ft_strlen(args[i]) != (size_t)int_len)
			return (FALSE);
		while (args[i][j])
		{
			if (ft_isdigit(args[i][j]) == 0 && args[i][j] != '-')
				return (FALSE);
			j ++;
		}
		i ++;
	}
	return (doublon_check(argc, args));
}

t_bool	doublon_check(int argc, char **args)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 2)
		i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(args[i], args[j]) == 0)
				return (FALSE);
			j ++;
		}
		i ++;
	}
	return (TRUE);
}

size_t	split_len(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i ++;
	return (i);
}

t_bool	doublon_check_split(int argc, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)split_len(args))
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(args[i], args[j]) == 0)
			{
				free_split(args);
				return (FALSE);
			}
			j ++;
		}
		i ++;
	}
	return (TRUE);
}
