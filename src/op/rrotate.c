/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:01:59 by achu              #+#    #+#             */
/*   Updated: 2025/03/16 17:04:12 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Last become First in the stack a
void	rra(t_list **a, int is_w)
{
	t_list	*temp;

	if (!*a)
		return ;
	temp = *a;
	temp = temp->previous;
	*a = temp;
	if (is_w)
		write(1, "rra\n", 4);
}

// Last become First in the stack b
void	rrb(t_list **b, int is_w)
{
	t_list	*temp;

	if (!*b)
		return ;
	temp = *b;
	temp = temp->previous;
	*b = temp;
	if (is_w)
		write(1, "rrb\n", 4);
}

// Last become First in the stack a and b
void	rrr(t_list **a, t_list **b, int is_w)
{
	rra(a, 0);
	rrb(b, 0);
	if (is_w)
		write(1, "rrr\n", 4);
}
