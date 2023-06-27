/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:42:06 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/06/27 12:48:25 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	*buff;
	char	*line;
	size_t	i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	i = 0;
	buff = ft_strnew(BUFFER_SIZE);
	line = ft_strnew(BUFFER_SIZE);
	while (1)
	{
		if (i == BUFFER_SIZE)
		{
			line = ft_strjoin(line, ft_strdup(buff));
			free(buff);
			buff = ft_strnew(BUFFER_SIZE);
			i = 0;
		}
		if (read(fd, &buff[i], 1))
		{
			if (buff[i] == '\n')
				return (ft_strjoin(line, ft_strdup(buff)));
			i ++;
		}
		else
			break;
	}
	if (line[0] || buff[0])
		return (ft_strjoin(line, ft_strdup(buff)));
	return (NULL);
}

// int main(void)
// {
// 	int fd = open("test", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }