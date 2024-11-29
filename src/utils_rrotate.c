/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:01:59 by achu              #+#    #+#             */
/*   Updated: 2024/11/25 15:01:59 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_list **a)
{
	t_list	*temp;

	temp = *a;
	temp = temp->previous;
	*a = temp;
}

void	rrb(t_list **b)
{
	t_list	*temp;

	temp = *b;
	temp = temp->previous;
	*b = temp;
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
