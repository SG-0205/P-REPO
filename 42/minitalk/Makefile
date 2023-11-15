LIBFT = includes/ft_printf/libftprintf.a

CC = gcc -Wall -Werror -Wextra -g3
CCFLAGS = cc -Wall -Werror -Wextra -g3

SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c client_utils.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)


all: $(LIBFT) $(SERVER) $(CLIENT) clean

$(SERVER): $(OBJS_SERVER) $(LIBFT)
		${CCFLAGS} ${OBJS_SERVER} includes/ft_printf/libftprintf.a -o ${SERVER}

$(CLIENT): $(OBJS_CLIENT) $(LIBFT)
		${CCFLAGS} ${OBJS_CLIENT} includes/ft_printf/libftprintf.a -o ${CLIENT}

$(LIBFT):
		make all -C ./includes/ft_printf/

clean:	
		make clean -C ./includes/ft_printf/
		rm -rf ${OBJS_SERVER} ${OBJS_CLIENT} ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS}

fclean:	clean
		make fclean -C ./includes/ft_printf/
		rm -rf $(SERVER) $(CLIENT)

re:	fclean all