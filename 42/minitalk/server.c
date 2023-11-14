/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:25:45 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/11/14 02:48:46 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include <unistd.h>

t_servdata	*g_servdata;

void	exit_and_free(int sigid)
{
	if (sigid == SIGINT)
	{
		free(g_servdata->received_msg);
		free(g_servdata);
		exit(0);
	}
}

void	print_messages(char **messages, char *client_pid)
{
	int		i;

	i = -1;
	while (messages[++i])
	{
		ft_printf(GREEN_TEXT DIM_TEXT "(%s): " RESET_COLOR, client_pid);
		ft_printf(BLUE_TEXT ITALIC_TEXT "\"%s\"\n"
			NO_ITALIC_TEXT RESET_COLOR, messages[i]);
		if ((size_t)i == ft_array_len(messages))
			kill(ft_atoi(client_pid), SIGUSR1);
		else
			kill(ft_atoi(client_pid), SIGUSR2);
	}
}

void	split_message(void)
{
	char	**extract_pid;
	char	**messages;

	extract_pid = ft_split(g_servdata->received_msg, PID_SEPARATOR);
	// ft_printf("split[0] =\t%s\nsplit[1] =\t%s\nNON SPLIT =\t%s\n", splitted_msg[0], splitted_msg[1], g_servdata->received_msg);
	if (!extract_pid)
		exit_and_free(SIGINT);
	messages = ft_split(extract_pid[1], MSG_SEPARATOR);
	if (!messages)
		exit_and_free(SIGINT);
	print_messages(messages, extract_pid[0]);
	g_servdata->received_bits = 0;
	ft_bzero(g_servdata->received_msg, ft_lentillc(g_servdata->received_msg, END_SEPARATOR));
	g_servdata->recoded_char = 0;
	(ft_free_array(extract_pid), ft_free_array(messages));
}

void	recode_message(int sigid)
{
	if (sigid == SIGUSR2)
		g_servdata->recoded_char |= (1 << g_servdata->received_bits);
	g_servdata->received_bits += 1;
	// ft_printf("BITS: %d\n", g_servdata->received_bits);
	if (g_servdata->received_bits == 8)
	{
		g_servdata->received_bits = 0;
		g_servdata->recoded_char ++;
		g_servdata->recoded_char *= -1;
		g_servdata->received_msg = ft_strjoin(g_servdata->received_msg,
				&g_servdata->recoded_char);
		// ft_printf("Décodé: %c - ASCII(%d)\n", g_servdata->recoded_char, g_servdata->recoded_char);
		if (g_servdata->recoded_char == END_SEPARATOR)
			split_message();
		g_servdata->recoded_char = 0;
	}
}

void	init_data(void)
{
	g_servdata = (t_servdata *)malloc(sizeof(t_servdata));
	if (!g_servdata)
		exit(1);
	g_servdata->received_bits = 0;
	g_servdata->received_msg = (char *)malloc(sizeof(char) * 2);
	if (!g_servdata->received_msg)
		(free(g_servdata), exit(1));
	g_servdata->recoded_char = 0;
}

int	main(void)
{
	init_data();
	ft_printf(MAGENTA_TEXT "PID Serveur:\t-=>[%d]<=-\n\n" RESET_COLOR, getpid());
	signal(SIGUSR1, recode_message);
	signal(SIGUSR2, recode_message);
	signal(SIGINT, exit_and_free);
	while (1)
		;
	return (0);
}
