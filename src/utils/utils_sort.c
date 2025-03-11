/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:26:14 by achu              #+#    #+#             */
/*   Updated: 2025/03/11 02:15:32 by achu             ###   ########.fr       */
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

static int	ft_posstep(t_list **b)
{
	int		step;
	int		max;
	t_list	*temp;

	step = 0;
	temp = *b;
	max = get_max(*b);
	if ((*b)->nb == max)
		return (0);
	while (temp->next != *b)
	{
		if (temp->nb == max)
			return (step);
		temp = temp->next;
		step++;
	}
	return (0);
}

static int	ft_negstep(t_list **b)
{
	int		step;
	int		max;
	t_list	*temp;

	step = 0;
	temp = *b;
	max = get_max(*b);
	if ((*b)->nb == max)
		return (0);
	while (temp->previous != *b)
	{
		if (temp->nb == max)
			return (step);
		temp = temp->previous;
		step--;
	}
	return (0);
}

void	test(t_list **a, t_list **b)
{
	int	pos;
	int	neg;
	int	result;

	pos = ft_posstep(b);
	neg = ft_negstep(b);
	result = ft_mincmp(pos, neg);
	if (ft_abs(result) > 20)
		pa(a, b);
	else
	{
		do_rborrb(b, result);
		pa(a, b);
	}
	ra(a);
}
