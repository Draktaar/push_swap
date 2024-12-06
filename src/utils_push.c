/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:02:15 by achu              #+#    #+#             */
/*   Updated: 2024/12/06 01:15:28 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*temp_b;

	if (!*b)
		return ;
	temp_b = *b;
	if ((*b)->next == *b)
	{
		(*b)->next = NULL;
		(*b)->previous = NULL;
		*b = NULL;
	}
	else
	{
		(*b)->next->previous = temp_b->previous;
		(*b)->previous->next = temp_b->next;
		*b = temp_b->next;
	}
	if (!a || !*a)
	{
		*a = temp_b;
		(*a)->next = temp_b;
		(*a)->previous = temp_b;
		return ;
	}
	temp_b->previous = (*a)->previous;
	temp_b->next = *a;
	(*a)->previous->next = temp_b;
	(*a)->previous  = temp_b;
	*a = temp_b;
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp_a;

	if (!*a)
		return ;
	temp_a = *a;
	if ((*a)->next == *a)
	{
		(*a)->next = NULL;
		(*a)->previous = NULL;
		*a = NULL;
	}
	else
	{
		(*a)->next->previous = temp_a->previous;
		(*a)->previous->next = temp_a->next;
		*a = temp_a->next;
	}
	if (!b || !*b)
	{
		*b = temp_a;
		(*b)->next = temp_a;
		(*b)->previous = temp_a;
		return ;
	}
	temp_a->previous = (*b)->previous;
	temp_a->next = *b;
	(*b)->previous->next = temp_a;
	(*b)->previous = temp_a;
	*b = temp_a;
	write(1, "pb\n", 3);
}
