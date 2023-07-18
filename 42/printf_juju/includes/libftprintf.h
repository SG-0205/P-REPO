/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:13:56 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/05/23 16:47:36 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define SPEC "csdiupxX%"
# define BASE_HEX_MIN "0123456789abcdef"
# define BASE_HEX_MAJ "0123456789ABCDEF"
# define BASE_TEN "0123456789"

void	ft_putunsigned(unsigned long long nbr, const char *base, int *len);
void	ft_putnbr_base_f(int nbr, const char *base, int *len);
void	ft_printpointer(unsigned long long pointer, const char *base, int *len);
void	ft_putchar_f(char c, int *len);
void	ft_putstr_f(const char *str, int *len);
int		ft_printf(const char *format, ...);

#endif