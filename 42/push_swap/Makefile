# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 17:57:21 by sgoldenb          #+#    #+#              #
#    Updated: 2023/10/11 18:33:10 by sgoldenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc
RM = rm -f

SRC = args_checking.c checks.c initialization.c input_parsing.c list_management_low.c list_management_high.c push_swap.c radix_utils_1.c radix_utils_2.c radix.c stack_operations_1.c stack_operations_2.c stack_operations_3.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ) libft
	$(AR) $@ $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -lft

all: $(NAME)

libft:
	make all -C libft

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re libft
