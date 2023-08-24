/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:16:26 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/08/24 11:59:32 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_by_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	mlx_destroy_display(mlx->mlx_ptr);
	mlx_loop_end(mlx->mlx_ptr);
	free_mlx(mlx);
	exit(0);
}

int key_hooks(int keycode, t_mlx *mlx)
{
	if (keycode == 65421)
		ft_putendl("Ouverture de la fenêtre OK.");
	
	if (keycode == 65307)	//Ferme quand ESC est pressé
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->window);
		mlx_destroy_display(mlx->mlx_ptr);
		mlx_loop_end(mlx->mlx_ptr);
		free_mlx(mlx);
		exit(0);
	}
	else if (keycode == 65361)	//Vue vers la gauche
	{
		mlx->view->x_min -= 0.5;
		mlx->view->x_max -= 0.5;
		//DRAW_AGAIN
	}
	else if (keycode == 65363)	//Vue vers la droite
	{
		mlx->view->x_min += 0.5;
		mlx->view->x_max += 0.5;
		//DRAW_AGAIN
	}
	else if (keycode == 65362)	//Vue vers le haut
	{
		mlx->view->y_min += 0.5;
		mlx->view->y_max += 0.5;
		//DRAW_AGAIN
	}
	else if (keycode == 65364)	//Vue vers le bas
	{
		mlx->view->y_min -= 0.5;
		mlx->view->y_max -= 0.5;
		//DRAW_AGAIN
	}
	if (keycode != 65421)
	{
		ft_putendl(ft_strjoin("Keycode détecté : ", ft_itoa(keycode)));
	}
}

void	hooks(t_mlx *data)
{
	mlx_hook(data->window, DESTROYNOTIFY, KEYRELEASEMASK, close_by_window, data);
	mlx_key_hook(data->window, key_hooks, data);
}