/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:25:52 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/11/08 18:05:27 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include <unistd.h>

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
		usleep(100);
	}
}

void	message_received(int sigid)
{
	if (sigid == SIGUSR1)
	{
		ft_putendl("Message reçu!");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*pid_prefix;
	char	*message;

	if (argc != 3)
		return (1);
	i = -1;
	while (argv[1][++i])
		if (ft_isdigit(argv[1][i]) == 0)
			return (1);
	i = 0;
	pid_prefix = ft_itoa(getpid());
	while (pid_prefix[i])
		i ++;
	pid_prefix[i] = MSG_SEPARATOR;
	message = ft_strjoin(pid_prefix, ft_strdup(argv[2]));
	if (!message)
		return (1);
	i = -1;
	signal(SIGUSR1, message_received);
	while (message[++i])
		send_str_bits(message[i], ft_atoi(argv[1]));
	send_str_bits(message[i], ft_atoi(argv[1]));
	ft_printf("%d\n", getpid());
	while (1)
		usleep(1);
	return (0);
}
