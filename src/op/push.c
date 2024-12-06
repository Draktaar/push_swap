/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:02:15 by achu              #+#    #+#             */
/*   Updated: 2024/12/06 20:16:00 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	is_setup(t_list **stack, t_list *temp)
{
	if ((*stack)->next == *stack)
	{
		(*stack)->next = NULL;
		(*stack)->previous = NULL;
		*stack = NULL;
	}
	else
	{
		(*stack)->next->previous = temp->previous;
		(*stack)->previous->next = temp->next;
		*stack = temp->next;
	}
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!*b)
		return ;
	temp = *b;
	is_setup(b, temp);
	if (!a || !*a)
	{
		*a = temp;
		(*a)->next = temp;
		(*a)->previous = temp;
		write(1, "pa\n", 3);
		return ;
	}
	temp->previous = (*a)->previous;
	temp->next = *a;
	(*a)->previous->next = temp;
	(*a)->previous  = temp;
	*a = temp;
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!*a)
		return ;
	temp = *a;
	is_setup(a, temp);
	if (!b || !*b)
	{
		*b = temp;
		(*b)->next = temp;
		(*b)->previous = temp;
		write(1, "pb\n", 3);
		return ;
	}
	temp->previous = (*b)->previous;
	temp->next = *b;
	(*b)->previous->next = temp;
	(*b)->previous = temp;
	*b = temp;
	write(1, "pb\n", 3);
}
