# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 14:10:45 by achu              #+#    #+#              #
#    Updated: 2025/03/15 19:20:14 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

NAME =	push_swap
NAMEB =	checker

SRCDIR =	src
SRCBDIR =	bonus
INCDIR =	includes

LIBFT  =	lib/libft
PRINTF =	lib/printf
HEADERS =	$(INCDIR)/push_swap.h $(LIBFT)/libft.h $(PRINTF)/ft_printf.h

SRC =	op/push.c \
		op/swap.c \
		op/rotate.c \
		op/rrotate.c \
		utils/utils_init.c \
		utils/utils_list.c \
		utils/utils_sort.c \
		utils/utils_stack.c \
		init.c \
		ft_divconq.c \
		ft_sort.c \
		ft_mini_sort.c \
		main.c \

SRCB =	checker.c \

OBJS =	$(addprefix $(SRCDIR)/, $(SRC:.c=.o))
OBJSB =	$(addprefix $(SRCBDIR)/, $(SRCB:.c=.o))

all: $(NAME)

$(NAME): 	$(OBJS)
	$(MAKE) --no-print-directory -C $(LIBFT)
	$(MAKE) --no-print-directory -C $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a $(PRINTF)/printf.a -o $(NAME)

bonus: all $(NAMEB)

$(NAMEB): 	$(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) $(LIBFT)/libft.a $(PRINTF)/printf.a -o $(NAMEB)
	
%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -I $(LIBFT) -I $(PRINTF) -c $< -o $@

$(OBJS): 	$(HEADERS)

clean:
	$(MAKE) --no-print-directory clean -C $(LIBFT)
	$(MAKE) --no-print-directory clean -C $(PRINTF)
	rm -rf $(OBJS)
	rm -rf $(OBJSB)

fclean: clean
	$(MAKE) --no-print-directory fclean -C $(LIBFT)
	$(MAKE) --no-print-directory fclean -C $(PRINTF)
	rm -rf $(NAME)
	rm -rf $(NAMEB)

re: fclean all

.PHONY: all clean fclean re
