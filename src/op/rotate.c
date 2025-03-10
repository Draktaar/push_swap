/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:02:05 by achu              #+#    #+#             */
/*   Updated: 2025/03/10 16:56:35 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// First become last in the stack a
void	ra(t_list **a)
{
	t_list	*temp;

	if (!*a)
		return ;
	temp = *a;
	temp = temp->next;
	*a = temp;
	write(1, "ra\n", 3);
}

// First become last in the stack b
void	rb(t_list **b)
{
	t_list	*temp;

	if (!*b)
		return ;
	temp = *b;
	temp = temp->next;
	*b = temp;
	write(1, "rb\n", 3);
}

// First become last in the stack a and b
void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
