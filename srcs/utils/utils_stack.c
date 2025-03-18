/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:28:31 by achu              #+#    #+#             */
/*   Updated: 2025/03/16 21:03:28 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Search throught a stack and return the smallest number
int	get_min(t_list *stack)
{
	t_list	*temp;
	int		min;

	min = stack->nb;
	temp = stack->next;
	while (temp != stack)
	{
		if (temp->nb < min)
			min = temp->nb;
		temp = temp->next;
	}
	return (min);
}

// Search throught a stack and return the biggest number
int	get_max(t_list *stack)
{
	t_list	*temp;
	int		max;

	max = stack->nb;
	temp = stack->next;
	while (temp != stack)
	{
		if (temp->nb > max)
			max = temp->nb;
		temp = temp->next;
	}
	return (max);
}

// Depends on the number of step to take
// Do ra if the step are positive 
// Do rra if the step are negative 
void	do_raorra(t_list **a, int step)
{
	int	i;

	i = step;
	while (i != 0)
	{
		if (i < 0)
		{
			rra(a, 1);
			i++;
		}
		else
		{
			ra(a, 1);
			i--;
		}
	}
}

// Depends on the number of step to take
// Do rb if the step are positive 
// Do rrb if the step are negative 
void	do_rborrb(t_list **b, int step)
{
	int	i;

	i = step;
	while (i != 0)
	{
		if (i < 0)
		{
			rrb(b, 1);
			i++;
		}
		else
		{
			rb(b, 1);
			i--;
		}
	}
}
