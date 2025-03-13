/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:01:59 by achu              #+#    #+#             */
/*   Updated: 2025/03/13 20:24:25 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Last become First in the stack a
void	rra(t_list **a)
{
	t_list	*temp;

	if (!*a)
		return ;
	temp = *a;
	temp = temp->previous;
	*a = temp;
	write(1, "rra\n", 4);
}

// Last become First in the stack b
void	rrb(t_list **b)
{
	t_list	*temp;

	if (!*b)
		return ;
	temp = *b;
	temp = temp->previous;
	*b = temp;
	write(1, "rrb\n", 4);
}

// Last become First in the stack a and b
void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}

// Fake reverse rotate operator to preview step
void	rrt(t_list **stack)
{
	t_list	*temp;

	if (!*stack)
		return ;
	temp = *stack;
	temp = temp->previous;
	*stack = temp;
}
