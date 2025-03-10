/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:35:47 by achu              #+#    #+#             */
/*   Updated: 2025/03/10 21:12:19 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Split the stack a into multiple presorted chunck
static void	ft_divconq(t_list **a, t_list **b)
{
	int min;
	int	size;

	min = get_min(*a);
	size = (ft_abs(min) + ft_abs(get_max(*a))) / 8;
	while (*a)
	{
		if (!is_inchunk((*a), min + size))
			min += size + 1;
		if ((*a)->nb <= min + size)
		{
			if ((*a)->nb <= min + size / 2)
				pb(a, b); 
			else
			{
				pb(a, b);
				rb(b);
			}
		}
		else
			ra(a);
	}
}

static void	ft_sort(t_list **a, t_list **b)
{
	int	min;
	int	max;
	int	step;

	min = (*b)->nb;
	max = (*b)->nb;
	pa(a, b);
	while (*b)
	{
		step = is_brobrr(*a, *b, min, max);
		do_rborrb(b, step);
		ft_blabla(a, b, &min, &max);
	}
}

void	ft_pushswap(t_list **a, t_list **b)
{
	ft_divconq(a, b);
	ft_sort(a, b);
	while (!is_sorted(*a))
		ra(a);
}
