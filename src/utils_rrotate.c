/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:01:59 by achu              #+#    #+#             */
/*   Updated: 2024/11/25 15:01:59 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_list **a)
{
	t_list	*list;
	t_list	*temp;

	if (!a || !*a)
		return ;
	list = *a;
	while (list->next->next)
		list = list->next;
	temp = list->next;
	temp->previous = NULL;
	list->next = NULL;
	temp->next = *a;
	*a = temp;
	(*a)->next->previous = temp;
}

void	rrb(t_list **b)
{
	t_list	*list;
	t_list	*temp;

	if (!b || !*b)
		return ;
	list = *b;
	while (list->next->next)
		list = list->next;
	temp = list->next;
	temp->previous = NULL;
	list->next = NULL;
	temp->next = *b;
	*b = temp;
	(*b)->next->previous = temp;
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
