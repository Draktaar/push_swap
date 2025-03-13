/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:26:14 by achu              #+#    #+#             */
/*   Updated: 2025/03/13 02:21:50 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Depends on the number of step to take
// Do rb if the step are positive 
// Do rrb if the step are negative 
static void	do_rborrb(t_list **b, int step)
{
	int	i;

	i = step;
	while (i != 0)
	{
		if (i < 0)
		{
			rrb(b);
			i++;
		}
		else
		{
			rb(b);
			i--;
		}
	}
}

void	test(t_list **a, t_list **b)
{
	do_rborrb(b, ft_finder(*b, get_max(*b)));
	pa(a, b);
	while (*b)
	{
		while ((*a)->previous->nb < get_max(*a) && (*a)->previous->nb > get_max(*b))
			rra(a);
		while ((*b)->nb != get_max(*b) &&
		((*a)->previous->nb < get_max(*a) && (*b)->nb < (*a)->previous->nb))
			rrb(b);
		pa(a, b);
		if ((*b) && (*a)->nb < get_max(*b))
			ra(a);
	}
}
