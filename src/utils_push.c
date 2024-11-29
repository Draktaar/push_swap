/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:02:15 by achu              #+#    #+#             */
/*   Updated: 2024/11/25 15:02:15 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*temp_b;

	if (!*b)
		return ;
	temp_b = *b;
	(*b)->next->previous = temp_b->previous;
	(*b)->previous->next = temp_b->next;
	*b = temp_b->next;
	temp_b->next = NULL;
	if (!a || !*a)
	{
		*a = temp_b;
		return ;
	}
	(*a)->next->previous = temp_b;
	temp_b->next = *a;
	temp_b->previous = (*a)->previous;
	*a = temp_b;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	if (!*a)
		return ;
	temp_a = *a;
	(*a)->next->previous = temp_b->previous;
	(*a)->previous->next = temp_b->next;
	*a = temp_a->next;
	temp_a->next = NULL;
	if (!b || !*b)
	{
		*b = temp_a;
		return ;
	}
	(*b)->next->previous = temp_b;
	temp_b->next = *b;
	temp_b->previous = (*b)->previous;
	*b = temp_a;
}
