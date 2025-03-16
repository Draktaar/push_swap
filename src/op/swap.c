/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:01:52 by achu              #+#    #+#             */
/*   Updated: 2025/03/16 20:28:35 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// First and Next are swaped in the stack a
void	sa(t_list **a, int is_w)
{
	t_list	*swap1;
	t_list	*swap2;

	if (!a || !*a || !(*a)->next)
		return ;
	swap1 = *a;
	swap2 = (*a)->next;
	swap1->next = swap2->next;
	swap2->next->previous = swap1;
	swap2->next = swap1;
	swap2->previous = swap1->previous;
	swap1->previous->next = swap2;
	swap1->previous = swap2;
	*a = swap2;
	if (is_w)
		write(1, "sa\n", 3);
}

// First and Next are swaped in the stack b
void	sb(t_list **b, int is_w)
{
	t_list	*swap1;
	t_list	*swap2;

	if (!b || !*b || !(*b)->next)
		return ;
	swap1 = *b;
	swap2 = (*b)->next;
	swap1->next = swap2->next;
	swap2->next->previous = swap1;
	swap2->next = swap1;
	swap2->previous = swap1->previous;
	swap1->previous->next = swap2;
	swap1->previous = swap2;
	*b = swap2;
	if (is_w)
		write(1, "sb\n", 3);
}

// First and Next are swaped in the stack a and b
void	ss(t_list **a, t_list **b, int is_w)
{
	sa(a, 0);
	sb(b, 0);
	if (is_w)
		write(1, "ss\n", 3);
}
