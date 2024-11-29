/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:02:05 by achu              #+#    #+#             */
/*   Updated: 2024/11/25 15:02:05 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **a)
{
	t_list	*temp;
	t_list	*prev;
	t_list	*list;

	if (!a || !*a)
		return ;
	temp = *a;
	temp->next->previous = NULL;
	*a = temp->next;
	temp->next = NULL;
	list = *a;
	while (list->next)
		list = list->next;
	prev = list;
	temp->previous = prev;
	list->next = temp;
}

void	rb(t_list **b)
{
	t_list	*temp;
	t_list	*prev;
	t_list	*list;

	if (!b || !*b)
		return ;
	temp = *b;
	temp->next->previous = NULL;
	*b = temp->next;
	temp->next = NULL;
	list = *b;
	while (list->next)
		list = list->next;
	prev = list;
	temp->previous = prev;
	list->next = temp;
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
