/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:17:38 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/11/14 03:02:41 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	append_separator(char *str, char separator)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		i ++;
	str[i] = separator;
}

void	build_message(char **messages, t_clientdata *g_clidata)
{
	char	*tmp_input;
	int		i;
	int		j;

	i = -1;
	while (messages[++i])
	{
		j = 0;
		tmp_input = ft_strdup(messages[i]);
		if (!tmp_input)
			(destroy_data(), exit(1));
		append_separator(tmp_input, MSG_SEPARATOR);
		g_clidata->input = ft_strjoin(g_clidata->input, tmp_input);
		if (!g_clidata->input)
			(destroy_data(), exit(1));
		free(tmp_input);
	}
	append_separator(g_clidata->input, END_SEPARATOR);
	g_clidata->message = ft_strjoin(g_clidata->pid_prefix, g_clidata->input);
}

void	send_message(t_clientdata *g_clidata)
{
	int	i;

	i = 0;
	while (g_clidata->pid_prefix[i] != PID_SEPARATOR)
		i ++;
	g_clidata->pid_prefix[i] = 0;
	i = -1;
	while (g_clidata->message[++i])
		send_str_bits(g_clidata->message[i], g_clidata->serv_pid);
	send_str_bits(g_clidata->message[i], g_clidata->serv_pid);
}

void	wait_reception(void)
{
	int	i;

	i = -1;
	ft_printf(DIM_TEXT "En attente de confirmation");
	while (++i < 10)
		(ft_printf("."), sleep(1));
	ft_printf(RESET_COLOR RED_TEXT "\nPas de signal de reception, verifier PID serveur.\n"
		RESET_COLOR);
}