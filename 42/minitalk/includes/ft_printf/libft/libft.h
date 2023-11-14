/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:40:57 by sgoldenb          #+#    #+#             */
/*   Updated: 2023/11/13 23:33:18 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define TRUE 1
# define FALSE 0
# define ERROR 2

typedef int	t_bool;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void				*ft_memset(void *s, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);

size_t				ft_strlen(const char *s);
size_t				ft_lentillc(const char *s, char c);
size_t				ft_countwords(const char *s, char c);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *big,
						const char *little, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(const char *str);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_intlen(long int n, size_t *container);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);

char				*ft_itoa(int n);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_base(int nbr, char *base);

t_list				*ft_lstnew(void const *content);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstlink(size_t size, ...);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));

int					ft_cisar(char c, const char *array);

// Codes de couleurs ANSI pour le texte
# define RESET_COLOR "\x1b[0m"
# define BLACK_TEXT "\x1b[30m"
# define RED_TEXT "\x1b[31m"
# define GREEN_TEXT "\x1b[32m"
# define YELLOW_TEXT "\x1b[33m"
# define BLUE_TEXT "\x1b[34m"
# define MAGENTA_TEXT "\x1b[35m"
# define CYAN_TEXT "\x1b[36m"
# define WHITE_TEXT "\x1b[37m"

// Codes de couleurs ANSI pour l'arrière-plan
# define BLACK_BG "\x1b[40m"
# define RED_BG "\x1b[41m"
# define GREEN_BG "\x1b[42m"
# define YELLOW_BG "\x1b[43m"
# define BLUE_BG "\x1b[44m"
# define MAGENTA_BG "\x1b[45m"
# define CYAN_BG "\x1b[46m"
# define WHITE_BG "\x1b[47m"

// Styles de texte
# define BOLD_TEXT "\x1b[1m"
# define DIM_TEXT "\x1b[2m"
# define UNDERLINE_TEXT "\x1b[4m"
# define BLINK_TEXT "\x1b[5m"
# define REVERSE_TEXT "\x1b[7m"
# define HIDDEN_TEXT "\x1b[8m"
# define ITALIC_TEXT "\x1b[3m"
# define NO_ITALIC_TEXT "\x1b[23m"

// Codes de contrôle de curseur
# define SAVE_CURSOR "\x1b[s"
# define RESTORE_CURSOR "\x1b[u"
# define HIDE_CURSOR "\x1b[?25l"
# define SHOW_CURSOR "\x1b[?25h"

#endif