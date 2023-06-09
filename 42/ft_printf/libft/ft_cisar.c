/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cisar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:15:39 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/03/29 18:11:16 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cisar(char c, const char *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i] == c)
			return (1);
		i ++;
	}
	return (0);
}
