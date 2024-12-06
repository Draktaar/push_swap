/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:01:59 by achu              #+#    #+#             */
/*   Updated: 2024/12/06 01:15:14 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
