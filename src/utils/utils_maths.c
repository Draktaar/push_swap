/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:28:31 by achu              #+#    #+#             */
/*   Updated: 2025/03/11 15:54:55 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// Search throught a stack and return the smallest number
int	get_min(t_list *stack)
{
	t_list	*temp;
	int		min;

	min = stack->nb;
	temp = stack;
	while (temp->next != stack)
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
	temp = stack;
	while (temp->next != stack)
	{
		if (temp->nb > max)
			max = temp->nb;
		temp = temp->next;
	}
	return (max);
}
