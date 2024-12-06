/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:01:52 by achu              #+#    #+#             */
/*   Updated: 2024/12/06 01:14:59 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list **a)
{
	t_list	*swap1;
	t_list	*swap2;

	if (!a || !*a || !(*a)->next)
		return ;
	swap1 = *a;
	swap2 = (*a)->next;
	swap1->previous->next = swap2;
	swap2->next->previous = swap1;
	swap2->previous = swap1->previous;
	swap1->next = swap2->next;
	swap1->previous = swap2;
	swap2->next = swap1;
	*a = swap2;
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	t_list	*swap1;
	t_list	*swap2;

	if (!b || !*b || !(*b)->next)
		return ;
	swap1 = *b;
	swap2 = (*b)->next;
	swap1->previous->next = swap2;
	swap2->next->previous = swap1;
	swap2->previous = swap1->previous;
	swap1->next = swap2->next;
	swap1->previous = swap2;
	swap2->next = swap1;
	*b = swap2;
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
