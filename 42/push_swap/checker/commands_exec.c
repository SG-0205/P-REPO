/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:42:40 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/13 16:43:17 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	commands_checker(t_command *commands, t_stack *a, t_stack *b)
{
	t_command	*tmp;

	tmp = commands;
	while (tmp)
	{
		if (ft_strcmp(tmp->command, "pa\n") == 0 || ft_strcmp(tmp->command,
				"pb\n") == 0 || ft_strcmp(tmp->command, "sa\n") == 0
			|| ft_strcmp(tmp->command, "sb\n") == 0 || ft_strcmp(tmp->command,
				"rra\n") == 0 || ft_strcmp(tmp->command, "rrb\n") == 0
			|| ft_strcmp(tmp->command, "ra\n") == 0 || ft_strcmp(tmp->command,
				"rb\n") == 0 || ft_strcmp(tmp->command, "ss\n") == 0
			|| ft_strcmp(tmp->command, "rrr\n") == 0 || ft_strcmp(tmp->command,
				"rr\n") == 0)
			tmp = tmp->next;
		else
		{
			ft_lstclear_ch(&commands);
			free_all(a, b);
			error();
		}
	}
}

void	rotate_check(t_command *command, t_stack *a, t_stack *b)
{
	if (ft_strcmp(command->command, "rra\n") == 0)
		reverse_r_a_ch(a);
	else if (ft_strcmp(command->command, "rrb\n") == 0)
		reverse_r_b_ch(b);
	else if (ft_strcmp(command->command, "rrr\n") == 0)
		reverse_r_all_ch(a, b);
	else if (ft_strcmp(command->command, "ra\n") == 0)
		rotate_a_ch(a);
	else if (ft_strcmp(command->command, "rb\n") == 0)
		rotate_b_ch(b);
	else if (ft_strcmp(command->command, "rr\n") == 0)
		rotate_all_ch(a, b);
}

void	swap_check(t_command *command, t_stack *a, t_stack *b)
{
	if (ft_strcmp(command->command, "sa\n") == 0)
		swap_a_ch(a);
	else if (ft_strcmp(command->command, "sb\n") == 0)
		swap_b_ch(b);
	else if (ft_strcmp(command->command, "ss\n") == 0)
		swap_both_ch(a, b);
}

t_bool	exec_cmds(t_command *cmd_list, t_stack *a, t_stack *b)
{
	while (cmd_list)
	{
		if (ft_strcmp(cmd_list->command, "pa\n") == 0)
			push_a_ch(a, b);
		else if (ft_strcmp(cmd_list->command, "pb\n") == 0)
			push_b_ch(a, b);
		rotate_check(cmd_list, a, b);
		swap_check(cmd_list, a, b);
		cmd_list = cmd_list->next;
	}
	if (sort_check(a) == TRUE && b->size == 0)
		return (TRUE);
	else
		return (FALSE);
}
