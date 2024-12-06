# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 14:10:45 by achu              #+#    #+#              #
#    Updated: 2024/12/06 21:21:47 by achu             ###   ########.fr        #
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
		src/utils/utils_asort.c \
		src/utils/utils_bsort.c \
		src/utils/utils_list.c \
		src/utils/utils_maths.c \
		src/utils/utils_sort.c \
		src/main.c \
		src/mini_sort.c \
		src/pushswap.c \

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

i: all fclean

.PHONY: all clean fclean re
