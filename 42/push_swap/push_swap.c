/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:36:40 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/01 23:33:48 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putendl("Error");
	exit(0);
}

void	args_checker(int argc, char **args)
{
	int			i;
	int			j;
	long int	value;
	
	i = 1;
	value = ft_atoi(args[i]);
	while (i < argc)
	{
		j = 0;
		if (value > __INT_MAX__
			|| value < (__INT_MAX__ * -1 + 1))
				error();
		while (args[i][j])
		{
			if (ft_isdigit(args[i][j]) == 0)
				error();
			j ++;
		}
		i ++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		error();
	args_checker(argc, argv);
	
	return (0);
}