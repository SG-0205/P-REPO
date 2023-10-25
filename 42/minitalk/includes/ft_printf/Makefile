NAME = libftprintf.a
CC  = gcc
CFLAGS = -Wall -Wextra -Werror 
AR = ar -rc 
RM = rm -f

SRC =	ft_printf.c\
		ft_printpointer.c\
		ft_putchar_f.c\
		ft_putnbr_base_f.c\
		ft_putstr_f.c\
		ft_putunsigned.c\

PATH_SRC = srcs/

SRC_LIBFT = ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_cisar.c\
		ft_countwords.c\
		ft_intlen.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_lentillc.c\
		ft_lstadd_back.c\
		ft_lstadd_front.c\
		ft_lstclear.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstlast.c\
		ft_lstlink.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_lstsize.c\
		ft_memalloc.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putchar.c\
		ft_putendl_fd.c\
		ft_putendl.c\
		ft_putnbr_fd.c\
		ft_putnbr.c\
		ft_putnbrbase.c\
		ft_putstr_fd.c\
		ft_putstr.c\
		ft_split.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\

PATH_LIB = libft/

PRFEC = ${addprefix $(PATH_LIB), $(SRC_LIBFT)}
PREF_P = ${addprefix $(PATH_SRC), $(SRC)}
OBJ	= ${SRC:.c=.o}
OBJ_LIBFT = ${PRFEC:.c=.o}

%.o%.c: ${SRC} 
		$(CC) ${CFLAGS} -c -o $@ $< 

${NAME}:	${OBJ} $(OBJ_LIBFT)
			${AR} ${NAME} ${OBJ_LIBFT}
			${AR} ${NAME} ${OBJ}
		
all:	 ${NAME}

clean:
		${RM} ${OBJ} ${OBJ_LIBFT}

fclean: clean
		${RM} ${NAME}

re: fclean  all  

.PHONY: bonus all clean fclean re 