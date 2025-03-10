/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:02:15 by achu              #+#    #+#             */
/*   Updated: 2025/03/10 17:02:49 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Setup the First of stack to remove all link
// if the last of stack, NULL all link
// else relink his previous neighbour
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

// First of stack b in send to be First of stack a
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

// First of stack a in send to be First of stack b
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
