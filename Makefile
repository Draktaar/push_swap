# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 14:10:45 by achu              #+#    #+#              #
#    Updated: 2025/03/11 02:56:36 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
INCDIR = includes

SRC =	src/op/push.c \
		src/op/rotate.c \
		src/op/rrotate.c \
		src/op/swap.c \
		src/utils/ft_atoi.c \
		src/utils/ft_split.c \
		src/utils/ft_lst_utils.c \
		src/utils/utils_maths.c \
		src/utils/utils_pushswap.c \
		src/main.c \
		src/mini_sort.c \
		src/chunck.c \
		src/sort.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@
	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: all clean

.PHONY: all clean fclean re
