/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:04:25 by achu              #+#    #+#             */
/*   Updated: 2025/03/16 21:07:39 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Search form left to right of stack a number, and return the number of step 
static int	ft_posstep(t_list *stack)
{
	int		step;
	t_list	*temp;

	step = 0;
	temp = stack;
	while (temp->nb != get_min(stack))
	{
		temp = temp->next;
		step++;
	}
	return (step);
}

// Search form right to left of stack a number, and return the number of step 
static int	ft_negstep(t_list *stack)
{
	int		step;
	t_list	*temp;

	step = 0;
	temp = stack;
	while (temp->nb != get_min(stack))
	{
		temp = temp->previous;
		step--;
	}
	return (step);
}

// Return the smallest step to take to find that number
int	ft_findmin(t_list *stack)
{
	int	pos;
	int	neg;
	int	step;

	pos = ft_posstep(stack);
	neg = ft_negstep(stack);
	step = ft_mincmp(pos, neg);
	return (step);
}

// Return absolute value of a number
int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

// Return the comparaison of the smallest value from two absolute numbers
int	ft_mincmp(int a, int b)
{
	if (ft_abs(a) < ft_abs(b))
		return (a);
	else
		return (b);
}
