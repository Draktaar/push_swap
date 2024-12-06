# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 14:10:45 by achu              #+#    #+#              #
#    Updated: 2024/11/25 14:10:46 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
INCDIR = includes

SRC =	src/ft_atoi.c \
		src/ft_mini_sort.c \
		src/ft_pushswap.c \
		src/ft_split.c \
		src/main.c \
		src/utils_list.c \
		src/utils_maths.c \
		src/utils_push.c \
		src/utils_rotate.c \
		src/utils_rrotate.c \
		src/utils_sort.c \
		src/utils_swap.c \

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
