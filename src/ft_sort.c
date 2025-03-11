/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:26:14 by achu              #+#    #+#             */
/*   Updated: 2025/03/11 19:00:34 by achu             ###   ########.fr       */
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
	while (*b)
	{
		do_rborrb(b, ft_findmax(b, get_max(*b)));
		pa(a, b);
	}
}
