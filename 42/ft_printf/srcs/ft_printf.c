/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:43:36 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/05/19 20:49:16 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include "../libft/libft.h"
#include <stdio.h>

t_print	*ft_printinit(t_print *tab)
{
	tab->flag_blank = FALSE;
	tab->flag_hash = FALSE;
	tab->flag_zeropadding = FALSE;
	tab->flag_sign = FALSE;
	tab->flag_leftjustify = FALSE;
	tab->percent = 0;
	tab->min_width = 0;
	tab->max_width = 0;
	tab->total_len = 0;
	tab->flag_precision = FALSE;
	return (tab);
}

int	ft_atoic(char *to_int, int *stock)
{
	int	i;
	
	i = 0;
	while (to_int[i] >= '0' && to_int[i] <= '9')
	{
		*stock = *stock * 10 + (to_int[i] - 48);
		i ++;
	}
	return (i);
}

int	ft_widthcheck(t_print *tab, char *format)
{
	int	f_size;

	f_size = 0;
	if (ft_isdigit(format[f_size]) > 0 && tab->flag_precision == FALSE)
		f_size = ft_atoic(&format[f_size], &tab->min_width);
	else if (ft_isdigit(format[f_size]) > 0 && tab->flag_precision == TRUE)
		f_size = ft_atoic(&format[f_size], &tab->max_width);
	return (f_size);
}

int	ft_flagupdate(t_print *tab, char *format)
{
	int	f_size;

	f_size = 0;
	while (ft_cisar(format[f_size], SPEC) == FALSE)
	{
		if (format[f_size] == '.')
			tab->flag_precision = TRUE;
		else if (format[f_size] == '-')
			tab->flag_leftjustify = TRUE;
		else if (format[f_size] == '0')
			tab->flag_zeropadding = TRUE;
		else if (format[f_size] == ' ')
		{
			tab->flag_blank = TRUE;
			printf ("blank\n");
		}
		else if (format[f_size] == '#')
			tab->flag_hash = TRUE;
		else if (format[f_size] == '+')
			tab->flag_sign = TRUE;
		else if (format[f_size] == '*')
		{
			f_size = ft_widthcheck(tab, &format[f_size]);
		}
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
			ft_flagupdate(infos, &format[i]);
		}
	}
	return (i);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (ERROR);
	t_print	*new;
	new = (t_print *)malloc(sizeof(t_print));
	new = ft_printinit(new);
	ft_flagupdate(new, argv[1]);
	printf("s_print:\njustify:\t%d\nzeropadding:\t%d\nsign:\t%d\nblank:\t%d\nhash:\t%d\nprecision:\t%d\n",
		new->flag_leftjustify, new->flag_zeropadding, new->flag_sign, new->flag_blank, new->flag_hash, new->flag_precision);
	return (0);
}