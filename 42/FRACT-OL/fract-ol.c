/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 02:38:51 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/08/24 11:01:57 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_mlx(t_mlx *mlx)
{
	free(mlx->view);
	free(mlx);
}

int	main(int argc, char **argv)
{
	t_mlx 	*mlx;
	char	*formula_input;
	
	if (argc < 2)
	{
		print_options(AVAILABLE_FRACTALS);
		return (ERROR);
	}
	formula_input = (char *)malloc((ft_strlen(argv[1]) + 1) * sizeof(char));
	ft_strcpy(formula_input, argv[1]);
	if (check_formula_name(formula_input) == FALSE)
	{
		print_options(AVAILABLE_FRACTALS);
		return (ERROR);
	}
	mlx = mlx_setup(formula_input);
	hooks(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}