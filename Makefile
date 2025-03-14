# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 14:10:45 by achu              #+#    #+#              #
#    Updated: 2025/03/14 17:01:36 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra
NAME = push_swap
INCDIR = includes

SRC =	src/op/push.c \
		src/op/swap.c \
		src/op/rotate.c \
		src/op/rrotate.c \
		src/utils/ft_atoi.c \
		src/utils/ft_split.c \
		src/utils/ft_list.c \
		src/utils/utils_sort.c \
		src/utils/utils_stack.c \
		src/ft_divconq.c \
		src/ft_mini_sort.c \
		src/ft_sort.c \
		src/init.c \
		src/main.c \

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
