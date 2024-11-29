/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:01:52 by achu              #+#    #+#             */
/*   Updated: 2024/11/25 15:01:53 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list **a)
{
	t_list	*swap_1;
	t_list	*swap_2;

	if (!a || !*a)
		return ;
	swap_1 = *a;
	if (!swap_1->next)
		return ;
	swap_2 = swap_1->next;
	swap_1->next->next->previous = swap_1;
	swap_2->previous = NULL;
	swap_1->previous = swap_2;
	swap_1->next = swap_2->next;
	swap_2->next = swap_1;
	*a = swap_2;
}

void	sb(t_list **b)
{
	t_list	*swap_1;
	t_list	*swap_2;

	if (!b || !*b)
		return ;
	swap_1 = *b;
	if (!swap_1->next)
		return ;
	swap_2 = swap_1->next;
	swap_1->next->next->previous = swap_1;
	swap_2->previous = NULL;
	swap_1->previous = swap_2;
	swap_1->next = swap_2->next;
	swap_2->next = swap_1;
	*b = swap_2;
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}
