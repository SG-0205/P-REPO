/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 01:54:25 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/13 03:55:21 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_split(char **splitted_args)
{
	size_t	i;

	i = 0;
	while (splitted_args[i])
		i++;
	while (i--)
		free(splitted_args[i]);
	free(splitted_args);
}

void	argc_check(int *argc, char **argv, t_stack *a, t_stack *b)
{
	char	**splitted_argv;

	a->top_item = NULL;
	b->top_item = NULL;
	if (*argc < 2)
		(free_all(a, b), error());
	if (*argc == 2)
	{
		splitted_argv = ft_split(argv[1], ' ');
		if (args_checker_split(*argc, splitted_argv) == FALSE)
			(free_split(splitted_argv), free_all(a, b), error());
		stack_init_split(a, b, splitted_argv);
		free_split(splitted_argv);
	}
	else
	{
		if (args_checker(*argc, argv) == FALSE)
			(free_all(a, b), error());
		stack_init(a, b, *argc, argv);
	}
}

t_command	*move_listener(void)
{
	char		*input;
	t_command	*tmp;
	t_command	*commands;

	input = get_next_line(0);
	if (!input)
		return (NULL);
	commands = (ft_lstnew_ch(input));
	if (!commands)
		return (NULL);
	free(input);
	while (1)
	{
		input = get_next_line(0);
		if (!input)
			break ;
		tmp = ft_lstnew_ch(input);
		if (!tmp)
			ft_lstclear_ch(&commands);
		free(input);
		ft_lstadd_back_ch(&commands, tmp), free(tmp);
	}
	return (commands);
}

void	commands_checker(t_command *commands, t_stack *a, t_stack *b)
{
	t_command	*tmp;

	tmp = commands;
	while (tmp)
	{
		if (ft_strcmp(tmp->command, "pa\n") == 0 || ft_strcmp(tmp->command, "pb\n") == 0
			|| ft_strcmp(tmp->command, "sa\n") == 0 || ft_strcmp(tmp->command, "sb\n") == 0
			|| ft_strcmp(tmp->command, "rra\n") == 0 || ft_strcmp(tmp->command, "rrb\n") == 0
			|| ft_strcmp(tmp->command, "ss\n") == 0 || ft_strcmp(tmp->command, "rrr\n") == 0)
			tmp = tmp->next;
		else
			ft_lstclear_ch(&commands), free(commands), free_all(a, b), error();
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_command	*commands;

	if (argc < 2)
		return (0);
	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		error();
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		(free(a), error());
	argc_check(&argc, argv, a, b);
	commands = move_listener();
	commands_checker(commands, a, b);
}