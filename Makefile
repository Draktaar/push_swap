# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 14:10:45 by achu              #+#    #+#              #
#    Updated: 2025/03/15 15:39:47 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra
NAME = push_swap

INCDIR = includes
LIBFT  = lib/libft
PRINTF = lib/printf
HEADERS = $(INCDIR)/push_swap.h $(LIBFT)/libft.h $(PRINTF)/ft_printf.h

SRC =	src/op/push.c \
		src/op/swap.c \
		src/op/rotate.c \
		src/op/rrotate.c \
		src/utils/utils_list.c \
		src/utils/utils_sort.c \
		src/utils/utils_stack.c \
		src/ft_divconq.c \
		src/ft_mini_sort.c \
		src/ft_sort.c \
		src/init.c \
		src/main.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): 	$(OBJS)
	$(MAKE) --no-print-directory -C $(LIBFT)
	$(MAKE) --no-print-directory -C $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -I $(LIBFT) -I $(PRINTF) -c $< -o $@

$(OBJS): 	$(HEADERS)

clean:
	$(MAKE) --no-print-directory clean -C $(LIBFT)
	$(MAKE) --no-print-directory clean -C $(PRINTF)
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) --no-print-directory fclean -C $(LIBFT)
	$(MAKE) --no-print-directory fclean -C $(PRINTF)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
