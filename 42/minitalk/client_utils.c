/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:17:38 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/11/15 04:20:42 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	append_separator(char **str, char separator)
{
	char	*null_str;

	null_str = (char *)malloc(sizeof(char) * 2);
	if (!*str || !null_str)
		return ;
	null_str[0] = separator;
	null_str[1] = 0;
	*str = ft_strjoin(*str, null_str);
	free(null_str);
}

void	build_message(char **messages, t_clientdata *g_clidata)
{
	char	*tmp_input;
	int		i;

	i = -1;
	while (messages[++i])
	{
		tmp_input = ft_strnew(ft_strlen(messages[i]) + 1);
		if (!tmp_input)
			(destroy_data(), exit(1));
		tmp_input = ft_strcpy(tmp_input, messages[i]);
		// ft_printf("%s\ttmp(1)\n", tmp_input);
		append_separator(&tmp_input, MSG_SEPARATOR);
		// ft_printf("%s\ttmp(2)\n", tmp_input);
		if (!g_clidata->input)
		{
			g_clidata->input = ft_strnew(ft_strlen(tmp_input) + 1);
			ft_strcat(g_clidata->input, tmp_input);
		}
		else
			g_clidata->input = ft_strjoin(g_clidata->input, tmp_input);
		// ft_printf("%s\n", g_clidata->input);
		if (!g_clidata->input)
			(destroy_data(), exit(1));
		// ft_bzero(tmp_input, ft_strlen(tmp_input));
		free(tmp_input);
		// tmp_input = NULL;
	}
	g_clidata->input[ft_strlen(g_clidata->input) - 1] = 0;
	g_clidata->message = ft_strjoin(g_clidata->pid_prefix, g_clidata->input);
	// ft_printf("%s\n", g_clidata->input);
}

void	send_message(t_clientdata *g_clidata)
{
	int	i;

	i = 0;
	while (g_clidata->pid_prefix[i] != PID_SEPARATOR)
		i++;
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
	ft_printf(RESET_COLOR RED_TEXT "\nPas de signal de reception, verifier PID serveur.\n" RESET_COLOR);
}
