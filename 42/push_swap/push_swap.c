/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:36:40 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/01 18:43:43 by sgoldenb         ###   ########.fr       */
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
	int	i;
	int	j;
	
	i = 1;
	if (argc == 1)
		error();
	while (i < argc)
	{
		j = 0;
		if (ft_atoi(args[i]) > __INT_MAX__
			|| ft_atoi(args[i]) < (__INT_MAX__ * -1 + 1))
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

	args_checker(argc, argv);
	
	return (0);
}