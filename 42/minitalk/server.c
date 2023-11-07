/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:25:45 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/11/07 02:12:09 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include <unistd.h>

t_servdata	*g_data;

void	recode_message(int sigid)
{
	if (sigid == SIGUSR2)
		*g_data->recoded_char |= (1 << g_data->received_bits);
	g_data->received_bits += 1;
	if (g_data->received_bits == 8)
	{
		g_data->received_bits = 0;
		g_data->received_msg = ft_strjoin(g_data->received_msg,
				g_data->recoded_char);
		g_data->recoded_char = 0;
	}
}

int	main(void)
{
	g_data = (t_servdata *)malloc(sizeof(t_servdata));
	g_data->received_bits = 0;
	g_data->received_msg = (char *)malloc(sizeof(char) * 2);
	g_data->recoded_char = 0;
	ft_printf("PID Serveur:\t-=>[%d]<=-\n", getpid());
	signal(SIGUSR1, recode_message);
	signal(SIGUSR2, recode_message);
	while (1)
		usleep(1);
	return (0);
}
