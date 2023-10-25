NAME = minitalk
SRVNAME = server
CLINAME = client
CC  = gcc
CFLAGS = -Wall -Wextra -Werror 
AR = ar -rc 
RM = rm -f

SRCSERV =	server.c

SRCCLI = 	client.c

OBJSERV	= ${SRCSERV:.c=.o}
OBJCLI = ${SRCCLI:.c=.o}

%.o%.c: ${SRCSERV} ${SRCCLI} 
		$(CC) ${CFLAGS} -c -o $@ $< 

${NAME}:	server client
		
all:	 ${NAME}

server: ${OBJSERV}
		make all -C includes/ft_printf
		${AR} ${OBJSERV} includes/ft_printf/libftprintf.a

clean:
		${RM} ${OBJSERV} ${OBJCLI}
		make clean -C includes/ft_printf

fclean: clean
		${RM} ${NAME}

re: fclean  all  

.PHONY: bonus all clean fclean re 