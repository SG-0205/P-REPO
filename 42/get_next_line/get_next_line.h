
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 24
#endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strcat(char *dst, char *src);
char	*ft_strdup(char *s);
char	*ft_strnew(size_t size);
char	*ft_strjoin(char *s1, char *s2);

char	*get_next_line(int fd);
#endif
