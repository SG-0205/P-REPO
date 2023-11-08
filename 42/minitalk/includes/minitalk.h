/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:36:23 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/11/08 17:45:14 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define MSG_SEPARATOR -5

# include "ft_printf/includes/libftprintf.h"
# include <signal.h>

typedef struct s_servdata
{
	char	recoded_char;
	char	*received_msg;
	int		received_bits;
}	t_servdata;

#endif