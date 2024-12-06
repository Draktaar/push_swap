/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:11:56 by achu              #+#    #+#             */
/*   Updated: 2024/12/05 18:29:50 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

//*** Initialize ***
int		ft_atoi(const char *str);
void	ft_clearsplit(char **split);
char	**ft_split(const char *str, char set);

//*** Linked List ***
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);

//*** Sorting ***
void	printlist(t_list *stack);
int		is_sorted(t_list *stack);
void	ft_pushswap(t_list **a, t_list **b);
void	ft_minisort(t_list **a, t_list **b);

///*** Maths ***
int		ft_abs(int nb);
int		get_min(t_list *stack);
int		get_max(t_list *stack);
int		ft_nbcmp(int nb, int max);

//*** Algo ***
int		is_inchunk(t_list *stack, int max);
int		is_aroarr(t_list *a, t_list *b);
int		is_brobrr(t_list *a, t_list *b);
int	is_min(int a, int b);

//*** Operation ***
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif