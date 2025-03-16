/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:11:56 by achu              #+#    #+#             */
/*   Updated: 2025/03/16 21:06:00 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAXINT "2147483647"
# define MININT "-2147483648"

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_list
{
	int				nb;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

/// *** Initialize ***
int		ft_init(t_list **stack, int ac, char **av);

/// *** Double Circular Linked List ***
t_list	*ft_stack_new(int content);
void	ft_stack_addback(t_list **lst, t_list *new);
int		ft_stack_size(t_list *lst);
void	ft_stack_clear(t_list **lst);

/// *** Sorting ***
void	ft_sort(t_list **a, t_list **b);
void	ft_divconq(t_list **a, t_list **b, int size);
void	ft_minisort(t_list **a, t_list **b);

/// *** Helper ***
void	printlist(t_list *stack);
int		is_sorted(t_list *stack);
int		ft_abs(int nb);
int		ft_mincmp(int a, int b);
int		get_min(t_list *stack);
int		get_max(t_list *stack);
void	do_raorra(t_list **a, int step);
void	do_rborrb(t_list **b, int step);
int		ft_findmax(t_list *stack);
int		ft_findmin(t_list *stack);

/// *** Operation ***
void	sa(t_list **a, int is_w);
void	sb(t_list **b, int is_w);
void	ss(t_list **a, t_list **b, int is_w);
void	pa(t_list **a, t_list **b, int is_w);
void	pb(t_list **a, t_list **b, int is_w);
void	ra(t_list **a, int is_w);
void	rb(t_list **b, int is_w);
void	rr(t_list **a, t_list **b, int is_w);
void	rra(t_list **a, int is_w);
void	rrb(t_list **b, int is_w);
void	rrr(t_list **a, t_list **b, int is_w);

#endif