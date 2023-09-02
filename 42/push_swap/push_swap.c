/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:36:40 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/09/02 23:01:52 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putendl("Error");
	exit(0);
}

void	doublon_check(int argc, char **args)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(args[i], args[j]) == 0)
				error();
			j ++;
		}
		i ++;
	}
}

void	input_checker(int argc, char **args)
{
	int			i;
	int			j;
	long int	value;
	
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(args[i]);
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
	doublon_check(argc, args);
}

void	init_stacks(t_stack *stack_a, t_stack *stack_b, int argc, char **args)
{
	int		i;
	void	*value;
	t_list	*first_elem;
	t_list	*stack_elem;

	i = 1;
	ft_memcpy(value, ft_atoi(args[i]));
	first_elem = ft_lstnew((void *)&value);
	i ++;
	while (i < argc)
	{
		value = ft_atoi(args[i]);
		stack_elem = ft_lstnew((void *)&value);
		ft_lstadd_back(&first_elem, stack_elem);
		i ++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		error();
	input_checker(argc, argv);
	
	return (0);
}