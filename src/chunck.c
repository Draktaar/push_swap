/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:35:47 by achu              #+#    #+#             */
/*   Updated: 2025/03/11 02:54:37 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_raorra(t_list **stack, int max)
{
	int		pos;
	int		neg;
	int		result;
	t_list	*temp;

	pos = 0;
	neg = 0;
	temp = *stack;
	while (temp->next != *stack)
	{
		if (temp->nb <= max)
			break ; 
		temp = temp->next;
		pos++;
	}
	temp = *stack;
	while (temp->previous != *stack)
	{
		if (temp->nb <= max)
			break ; 
		temp = temp->previous;
		neg--;
	}
	result = ft_mincmp(pos, neg);
	return (result);
}

// Depends on the number of step to take
// Do ra if the step are positive 
// Do rra if the step are negative 
static void	do_raorra(t_list **a, int step)
{
	int	i;

	i = step;
	while (i != 0)
	{
		if (i < 0)
		{
			rra(a);
			i++;
		}
		else
		{
			ra(a);
			i--;
		}
	}
}

// Split the stack a into multiple presorted chunck
void	ft_divconq(t_list **a, t_list **b, int size)
{
	int min;
	int	chunck;

	min = get_min(*a);
	chunck = (ft_abs(get_min(*a)) + ft_abs(get_max(*a))) / size;
	while (*a)
	{
		if (!is_undermax(*a, min + chunck))
			min += (chunck + 1);
		if ((*a)->nb <= min + chunck)
		{
			if ((*a)->nb <= min + chunck / 2)
				pb(a, b); 
			else
			{
				pb(a, b);
				rb(b);
			}
		}
		else
			do_raorra(a, ft_raorra(a, min + chunck));
	}
}
