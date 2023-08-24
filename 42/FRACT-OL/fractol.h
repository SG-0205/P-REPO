/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 22:32:34 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/08/24 11:03:49 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "mlx_keys.h"

# define AVAILABLE_FRACTALS "mandelbrot,julia"
# define TITLE "<FRACT-OL> //"

typedef struct s_view
{
	double  x_min;
	double  y_min;
	double	x_max;
	double	y_max;
}   t_view;

typedef struct s_mlx
{
	void    *mlx_ptr;
	void    *window;
	t_view	*view;
}   t_mlx;

void	hooks(t_mlx *data);
int 	key_hooks(int keycode, t_mlx *mlx);
int		close_by_window(t_mlx *data);
void	print_options(char *options);
t_bool	check_formula_name(char *formula_name);
t_mlx	*mlx_setup(char *formula_name);
void	*view_init(t_mlx *to_init);
void	free_mlx(t_mlx *mlx);


#endif