/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:54:04 by achu              #+#    #+#             */
/*   Updated: 2025/03/10 17:05:04 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp->next != stack)
	{
		if (temp->next->nb < temp->nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_valid(t_list *a, t_list *b)
{
	if (a->previous->nb < b->nb && b->nb < a->nb)
		return (1);
	return (0);
}

int	is_minamax(t_list *a, int find)
{
	if (a->nb == find)
		return (1);
	return (0);
}

int	is_inchunk(t_list *stack, int max)
{
	t_list	*temp;

	temp = stack;
	while (temp->next != stack)
	{
		if (temp->nb <= max)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	rorr(t_list **stack, int step)
{
	int	i;

	i = step;
	while (i != 0)
	{
		if (i < 0)
		{
			rra(stack);
			i++;
		}
		else
		{
			ra(stack);
			i--;
		}
	}
}
