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
		(*a)->next = temp_b;
		(*a)->previous = temp_b;
		return ;
	}
	temp_b->next = *a;
	temp_b->previous = (*a)->previous;
	(*a)->previous->next = temp_b;
	(*a)->previous = temp_b;
	*a = temp_b;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp_a;

	if (!*a)
		return ;
	temp_a = *a;
	(*a)->next->previous = temp_a->previous;
	(*a)->previous->next = temp_a->next;
	*a = temp_a->next;
	temp_a->next = NULL;
	if (!b || !*b)
	{
		*b = temp_a;
		(*b)->next = temp_a;
		(*b)->previous = temp_a;
		return ;
	}
	temp_a->next = *b;
	temp_a->previous = (*b)->previous;
	(*b)->previous->next = temp_a;
	(*b)->previous = temp_a;
	*b = temp_a;
}
