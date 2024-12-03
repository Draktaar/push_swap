/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:35:47 by achu              #+#    #+#             */
/*   Updated: 2024/12/03 22:25:28 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_initmedian(t_list **a, t_list **b)
{
	int min;
	int	len;
	int	size;

	min = get_min(*a);
	len = ft_lstsize(*a);
	size = ft_abs(min) + ft_abs(get_max(*a));
	size /= 4;
	while (len > 0)
	{
		if (!is_chunk((*a), min + size))
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
			len--;
		}
		else
			ra(a);
	}
}

void	ft_sort(t_list **a, t_list **b)
{
	ft_initmedian(a, b);
	printf("test A");
	printlist(*a);
	printf("test B");
	printlist(*b);
}
