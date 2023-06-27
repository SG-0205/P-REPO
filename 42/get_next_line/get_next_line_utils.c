/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:20:07 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/06/27 12:36:50 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, char *src)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i ++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strcat(char *dst, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dst[i])
		i ++;
	while (src[j])
	{
		dst[i] = src[j];
		i ++;
		j ++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(char *s)
{
	int		size;
	char	*new;

	if (!s)
		return (NULL);
	new = NULL;
	size = ft_strlen(s);
	new = (char *)malloc(size * sizeof(char) + 1);
	if (!new)
		return (NULL);
	ft_strcpy(new, s);
	return (new);
}

char	*ft_strnew(size_t size)
{
	char	*strnew;
	size_t	i;

	i = 0;
	strnew = (char *)malloc((size + 1) * sizeof(char));
	if (!strnew)
		return (NULL);
	while (i <= size)
		strnew[i++] = '\0';
	return (strnew);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	new_str = ft_strnew(((ft_strlen(s1)) + (ft_strlen(s2))));
	if (!new_str)
		return (NULL);
	ft_strcat(new_str, s1);
	ft_strcat(new_str, s2);
	return (new_str);
}

