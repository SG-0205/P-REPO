/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:36:23 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/11/15 03:36:29 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define PID_SEPARATOR -127
# define MSG_SEPARATOR -126
# define END_SEPARATOR -125

# include "ft_printf/includes/libftprintf.h"
# include <signal.h>

typedef struct s_servdata
{
	char	recoded_char;
	char	*received_msg;
	int		received_bits;
}	t_servdata;

typedef struct s_clientdata
{
	char	*pid_prefix;
	char	*input;
	char	*message;
	int		serv_pid;
}	t_clientdata;

void	append_separator(char **str, char separator);
void	build_message(char **messages, t_clientdata *g_clidata);
void	send_message(t_clientdata *g_clidata);
void	send_str_bits(char message_char, int server_pid);
void	wait_reception(void);
void	destroy_data(void);

#endif