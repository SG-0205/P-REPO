/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:04:24 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/08/24 10:37:11 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool	free_array(char **array, size_t len)
{
	while (len --)
		free(array[len]);
	free(array);
}

t_bool	check_formula_name(char *formula_name)
{
	char	**available_formulas;
	size_t	i;
	t_bool	is_equal;

	is_equal = FALSE;
	if (!formula_name || formula_name[0] == 0)
		return (FALSE);
	available_formulas = ft_split(AVAILABLE_FRACTALS, ',');
	if (!available_formulas)
		ft_putendl("ERREUR D'ALLOCATION DES OPTIONS DISPONIBLES");
	i = 0;
	while (available_formulas[i])
		if (ft_strcmp(formula_name, available_formulas[i++]) == 0)
			is_equal = TRUE;
	free_array(available_formulas, i);
	return (is_equal);
}

void	print_options(char *options)
{
	char	**splitted_options;
	size_t	i;

	splitted_options = ft_split(options, ',');
	if (!splitted_options)
		ft_putendl("ERREUR D'ALLOCATION DES OPTIONS DISPONIBLES");
	ft_putendl("\t<---ERREUR DE SAISIE--->\n\nFractales disponibles:");
	i = 0;
	while (splitted_options[i])
		ft_putendl(splitted_options[i++]);
	free_array(splitted_options, i);
}