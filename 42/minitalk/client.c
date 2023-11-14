/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:25:52 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/11/14 00:45:08 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include <unistd.h>

t_clientdata *g_clidata;

void	init_data(void)
{
	int	i;

	i = 0;
	g_clidata = (t_clientdata *)malloc(sizeof(t_clientdata));
	g_clidata->input = ft_strnew(1);
	if (!g_clidata->input)
		(free(g_clidata), exit(1));
	g_clidata->message = ft_strnew(1);
	if (!g_clidata->message)
		(free(g_clidata->input), free(g_clidata), exit(1));
	g_clidata->pid_prefix = ft_itoa(getpid());
	if (!g_clidata->pid_prefix)
		(free(g_clidata->input), free(g_clidata->message), free(g_clidata),
			exit(1));
	append_separator(g_clidata->pid_prefix, PID_SEPARATOR);
}

void	destroy_data(void)
{
	free(g_clidata->input);
	free(g_clidata->message);
	free(g_clidata->pid_prefix);
	free(g_clidata);
}

void	send_str_bits(char message_char, int server_pid)
{
	int	bit_scope;
	int	bit_mask;

	bit_mask = 1;
	bit_scope = -1;
	while (++bit_scope != 8)
	{
		if (message_char & (bit_mask << bit_scope))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(50);
	}
}

void	message_received(int sigid)
{
	if (sigid == SIGUSR1)
	{
		ft_putendl(GREEN_TEXT "Message reçu! - Fermeture du client"
			RESET_COLOR);
		free(g_clidata->input);
		free(g_clidata->message);
		free(g_clidata->pid_prefix);
		free(g_clidata);
		exit(0);
	}
	else if (sigid == SIGUSR2)
		ft_putendl(GREEN_TEXT "Message reçu!" RESET_COLOR);
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc < 3)
		return (1);
	i = -1;
	while (argv[1][++i])
		if (ft_isdigit(argv[1][i]) == 0)
			return (1);
	i = 0;
	init_data();
	build_message(&argv[2], g_clidata);
	signal(SIGUSR1, message_received);
	ft_printf("En attente de confirmation");
	i = -1;
	while (++i < 10)
		(ft_printf("."), sleep(1));
	ft_printf(RED_TEXT "\nPas de signal de reception, verifier PID serveur.\n" RESET_COLOR);
	destroy_data();
	return (0);
}
