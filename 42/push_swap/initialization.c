/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:13:12 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/09 18:51:43 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error()
{
	ft_putendl("Error");
	exit(0);
}

void	free_from_top(t_stack *stack, t_stack *empty)
{
	// t_list_ps	*prev;
	// t_list_ps	*tmp;
	
	if (!stack)
		return ;
	ft_lstclear_ps(&stack->top_item);
	free(stack);
	free(empty);
	error();
}

int	check_doub_int(t_stack *a)
{
	t_list_ps	*tmp;
	t_list_ps	*tmp2;

	tmp = a->top_item;
	while (tmp)
	{
		// ft_printf("tmp = %d\n", tmp->value);
		tmp2 = tmp->next;
		while (tmp2)
		{
			// ft_printf("\t%d =? %d\n", tmp2->value, tmp->value);
			if (tmp2->value == tmp->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
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
	if (check_doub_int(a) == 1)
		free_from_top(a, b);
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
	if (check_doub_int(a) == 1)
		(free_split(argv), free_from_top(a, b));
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
				{free_split(args);
				return (FALSE);}
			j ++;
		}
		i ++;
	}
	return (TRUE);
}

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
			|| ft_strlen(args[i]) != int_len)
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
			|| ft_strlen(args[i]) != int_len)
				return(FALSE);
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