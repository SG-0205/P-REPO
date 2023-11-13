/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:25:45 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/11/13 19:45:55 by sgoldenb         ###   ########.fr       */
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

void	split_message(void)
{
	char	**splitted_msg;

	splitted_msg = ft_split(g_servdata->received_msg, MSG_SEPARATOR);
	// ft_printf("split[0] =\t%s\nsplit[1] =\t%s\nNON SPLIT =\t%s\n", splitted_msg[0], splitted_msg[1], g_servdata->received_msg);
	if (!splitted_msg)
		exit(1);
	kill(ft_atoi(splitted_msg[0]), SIGUSR1);
	ft_printf("%s\tFROM\t%s\n", splitted_msg[1], splitted_msg[0]);
	g_servdata->received_bits = 0;
	ft_bzero(g_servdata->received_msg, ft_strlen(g_servdata->received_msg));
	g_servdata->recoded_char = 0;
	free(splitted_msg);
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
		ft_printf("Décodé: %c - ASCII(%d)\n", g_servdata->recoded_char, g_servdata->recoded_char);
		if (g_servdata->recoded_char == 0)
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
	{
		free(g_servdata);
		exit(1);
	}
	g_servdata->recoded_char = 0;
}

int	main(void)
{
	init_data();
	ft_printf("PID Serveur:\t-=>[%d]<=-\n", getpid());
	signal(SIGUSR1, recode_message);
	signal(SIGUSR2, recode_message);
	signal(SIGINT, exit_and_free);
	while (1)
		;
	return (0);
}
