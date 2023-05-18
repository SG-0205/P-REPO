# ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>

typedef	struct s_print
{
	va_list	arguments;
	int		width;
	int		precision;
	int		zero;
	int		point;
	int		pad_left;
	int		t_length;
	int		sign;
	int		is_zero;
	int		percent;
	int		space_flag;
	int		prefix;
}	t_print;


# endif