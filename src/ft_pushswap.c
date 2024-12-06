/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:35:47 by achu              #+#    #+#             */
/*   Updated: 2024/12/06 01:14:47 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_initmedian(t_list **a, t_list **b)
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
	int i;

	i = 0;
	min = (*b)->nb;
	max = (*b)->nb;
	pa(a, b);
	while (*b)
	{
		step = is_brobrr(*a, *b, min, max);
		rborrb(b, step);
		ft_blabla(a, b, &min, &max);
	}
}

void	ft_pushswap(t_list **a, t_list **b)
{
	ft_initmedian(a, b);
	ft_sort(a, b);
	while (!is_sorted(*a))
		ra(a);
}
