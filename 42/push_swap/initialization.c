/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:13:12 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/02 18:11:14 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error()
{
	ft_putendl("Error");
	exit(0);
}

void	stack_init(t_stack *a, t_stack *b, int argc, char **argv)
{
	int			i;
	t_list_ps	*new;
	t_list_ps	*top;

	i = 2;
	top = ft_lstnew_ps(ft_atoi(argv[1]));
	if (!top)
		error();
	while (i < argc)
	{
		new = ft_lstnew_ps(ft_atoi(argv[i]));
		if (!new)
			ft_lstclear_ps(&top);
		ft_lstadd_back_ps(&top, new);
		i ++;
	}
	a->size = (argc - 1);
	a->top_item = top;
	a->last_item = ft_lstlast_ps(top);
	b->last_item = NULL;
	b->top_item = NULL;
	b->size = 0;
}

void	stack_init_split(t_stack *a, t_stack *b, char **argv)
{
	int			i;
	t_list_ps	*new;
	t_list_ps	*top;

	i = 0;
	top = ft_lstnew_ps(ft_atoi(argv[0]));
	if (!top)
		error();
	while (argv[++i])
	{
		new = ft_lstnew_ps(ft_atoi(argv[i]));
		if (!new)
			ft_lstclear_ps(&top);
		ft_lstadd_back_ps(&top, new);
	}
	a->size = (i);
	a->top_item = top;
	a->last_item = ft_lstlast_ps(top);
	b->last_item = NULL;
	b->top_item = NULL;
	b->size = 0;
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

// int	t_isdigit2(char c)
// {
	
// }

void	args_checker(int argc, char **args)
{
	int	i;
	int	j;
	
	i = 1;
	if (argc == 1)
		error();
	if (argc == 2)
		i = 0;
	while (i < argc)
	{
		j = 0;
		if (ft_atoi(args[i]) > __INT_MAX__
			|| ft_atoi(args[i]) < (__INT_MAX__ * -1) + 1)
				error();
		while (args[i][j])
		{
			if (ft_isdigit(args[i][j]) == 0 && args[i][j] != '-')
				error();
			j ++;
		}
		i ++;
	}
	doublon_check(argc, args);
}