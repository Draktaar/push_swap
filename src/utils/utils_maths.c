/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:28:31 by achu              #+#    #+#             */
/*   Updated: 2024/12/06 20:16:13 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_mincmp(int a, int b)
{
	if (ft_abs(a) < ft_abs(b))
		return (a);
	else
		return (b);
}

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
