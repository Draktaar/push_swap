# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 14:10:45 by achu              #+#    #+#              #
#    Updated: 2025/03/16 21:04:42 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

EXECNAME =	push_swap
CHECKNAME =	checker

SRCDIR =	src
INCDIR =	includes
BONUSDIR =	bonus

LIBFT  =	lib/libft
PRINTF =	lib/printf
HEADERS =	$(INCDIR)/push_swap.h $(LIBFT)/libft.h $(PRINTF)/ft_printf.h

SRC =	op/push.c \
		op/swap.c \
		op/rotate.c \
		op/rrotate.c \
		utils/utils_math.c \
		utils/utils_init.c \
		utils/utils_list.c \
		utils/utils_sort.c \
		utils/utils_stack.c \
		init.c \
		ft_divconq.c \
		ft_sort.c \
		ft_mini_sort.c
EXECSRC =	push_swap.c
CHECKSRC =	checker.c

OBJS =	$(addprefix $(SRCDIR)/, $(SRC:.c=.o))
OBJSEXEC =	$(addprefix $(SRCDIR)/, $(EXECSRC:.c=.o))
OBJSBONUS =	$(addprefix $(BONUSDIR)/, $(CHECKSRC:.c=.o))

all: $(EXECNAME)

$(EXECNAME): 	$(OBJS) $(OBJSEXEC)
	$(MAKE) --no-print-directory -C $(LIBFT)
	$(MAKE) --no-print-directory -C $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(OBJSEXEC) $(LIBFT)/libft.a $(PRINTF)/printf.a -o $(EXECNAME)
	
$(CHECKNAME): 	$(OBJS) $(OBJSBONUS)
	$(CC) $(CFLAGS) $(OBJS) $(OBJSBONUS) $(LIBFT)/libft.a $(PRINTF)/printf.a -o $(CHECKNAME)

bonus: $(EXECNAME) $(CHECKNAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -I $(LIBFT) -I $(PRINTF) -c $< -o $@

$(OBJS): 	$(HEADERS)
$(OBJSEXEC): 	$(HEADERS)
$(OBJSBONUS): 	$(HEADERS)

clean:
	$(MAKE) --no-print-directory clean -C $(LIBFT)
	$(MAKE) --no-print-directory clean -C $(PRINTF)
	rm -rf $(OBJS)
	rm -rf $(OBJSEXEC)
	rm -rf $(OBJSBONUS)

fclean: clean
	$(MAKE) --no-print-directory fclean -C $(LIBFT)
	$(MAKE) --no-print-directory fclean -C $(PRINTF)
	rm -rf $(EXECNAME)
	rm -rf $(CHECKNAME)

re: fclean all

.PHONY: all clean fclean re
