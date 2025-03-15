/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:11:56 by achu              #+#    #+#             */
/*   Updated: 2025/03/15 15:34:55 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INTMAX = 2147483647

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
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
int		ft_atoi(const char *str);
char	**ft_split(const char *str, char set);
void	ft_clearsplit(char **split);

/// *** Linked List ***
t_list	*ft_stack_new(int content);
void	ft_stack_addback(t_list **lst, t_list *new);
void	ft_lstadd_previous(t_list **lst, t_list *new);
int		ft_stack_size(t_list *lst);
void	ft_stack_clear(t_list **lst);

/// *** Sorting ***
void	ft_sort(t_list **a, t_list **b);
void	ft_divconq(t_list **a, t_list **b, int size);
void	ft_minisort(t_list **a, t_list **b);

/// *** Helper ***
void	printlist(t_list *stack);
int		ft_abs(int nb);
int		ft_mincmp(int a, int b);
int		get_min(t_list *stack);
int		get_max(t_list *stack);
int		is_sorted(t_list *stack);
int		ft_findmax(t_list *stack);

/// *** Operation ***
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rt(t_list **stack);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	rrt(t_list **stack);

#endif