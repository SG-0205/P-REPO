/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:43:36 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/05/18 14:18:47 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include "../libft/libft.h"
#include <stdio.h>

t_print	*ft_printinit(t_print *tab)
{
	tab->pad_left = FALSE;
	tab->is_zero = FALSE;
	tab->percent = FALSE;
	tab->point = FALSE;
	tab->precision = FALSE;
	tab->sign = FALSE;
	tab->space_flag = FALSE;
	tab->t_length = 0;
	tab->width = 0;
	tab->zero = FALSE;
	tab->prefix = FALSE;
	return (tab);
}

int	ft_flagupdate(t_print *tab, char *format)
{
	int	f_size;
	
	f_size = 0;
	while (ft_cisar(format[f_size], "csdiupxX%") == FALSE)
	{
		if (format[f_size] == '.')
			tab->point = TRUE;
		else if (format[f_size] == '-')
			tab->pad_left = TRUE;
		else if (format[f_size] == '0')
			tab->width ++;
		else if (format[f_size] == ' ')
			tab->space_flag = TRUE;
		else if (format[f_size] == '#')
			tab->prefix = TRUE;
		f_size ++;
	}
	return (f_size);
}

int	ft_printf(char *format, ...)
{
	t_print	*infos;
	// int		return_val;
	int		i;

	infos = (t_print *)malloc(sizeof(t_print));
	if (!infos)
		return (-1);
	ft_printinit(infos);
	va_start(infos->arguments, format);
	i = -1;
	// return_val = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			ft_flagupdate(infos, format + i);
		}
	}
	return (i);
}

int main(void)
{
	printf("%d", ft_printf("%#--"));
}