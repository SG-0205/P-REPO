/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:25:45 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/10/25 17:33:36 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	add_zero(int sigusr1, char **binary_str)
{
	int	i;

	i = -1;
	if (sigusr1 == SIGUSR1)
	{
		while (*binary_str[i])
			i ++;
		*binary_str[i + 1] = (char *)malloc(sizeof(char));
		if (!*binary_str[i + 1])
			exit(2);
		*binary_str[i + 1] = '0';
	}
}

int	add_one(int sigusr2, char **binary_str)
{
	int	i;

	i = -1;
	if (sigusr2 == SIGUSR2)
	{
		while (*binary_str[i])
			i ++;
		*binary_str[i + 1] = (char *)malloc(sizeof(char));
		if (!*binary_str[i + 1])
			exit(2);
		*binary_str[i + 1] = '1';
	}
}

int	main(void)
{
	char	*binary_str;

	ft_printf("PID Serveur:\t%d\n", getpid());
	signal(SIGUSR1, add_zero(SIGUSR1, &binary_str));
	signal(SIGUSR2, add_one(SIGUSR2, &binary_str));
	while (!binary_str);
}
