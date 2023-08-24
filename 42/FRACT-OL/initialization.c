/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:04:50 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/08/24 10:39:19 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*view_init(t_mlx *to_init)
{
	to_init->view->x_max = 2.0;
	to_init->view->y_max = 2.0;
	to_init->view->x_min = -2.0;
	to_init->view->y_min = -2.0;
}

t_mlx	*mlx_setup(char *formula_name)
{
	t_mlx	*new;
	char	*title;

	title = ft_strjoin(TITLE, formula_name);
	new = (t_mlx *)malloc(sizeof(t_mlx));
	if (!new)
		return (NULL);
	new->mlx_ptr = mlx_init();
	if (!new->mlx_ptr)
		return (NULL);
	new->view = (t_view *)malloc(sizeof(t_view));
	if (!new->view)
		return (NULL);
	view_init(new);
	new->window = mlx_new_window(new->mlx_ptr, 800, 800, title);
	free(title);
	free(formula_name);
	return (new);
}