# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 17:57:21 by sgoldenb          #+#    #+#              #
#    Updated: 2023/10/13 17:34:05 by sgoldenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER_NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc
RM = rm -f

SRC = args_checking.c checks.c initialization.c input_parsing.c list_management_low.c list_management_high.c push_swap.c radix_utils_1.c radix_utils_2.c radix.c stack_operations_1.c stack_operations_2.c stack_operations_3.c
SRCBONUS = checker/checker.c checker/commands_exec.c checker/commands_management.c checker/stack_operations_1_ch.c checker/stack_operations_2_ch.c checker/stack_operations_3_ch.c checker/initialization_ch.c list_management_low.c list_management_high.c checks.c checker/input_parsing_ch.c checker/args_checking_ch.c

OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)

LIBFT = libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ) libft
	$(AR) $@ $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -lft

$(CHECKER_NAME): $(OBJBONUS) libft
	$(CC) $(CFLAGS) -o checker/$(CHECKER_NAME) $(OBJBONUS) -Llibft -lft

bonus: $(CHECKER_NAME)

all: $(NAME) $(CHECKER_NAME)

libft:
	make all -C libft

clean:
	$(RM) $(OBJ) $(OBJBONUS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME) $(CHECKER_NAME)/checker
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re libft bonus

