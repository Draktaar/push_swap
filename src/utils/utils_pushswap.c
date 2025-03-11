/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pushswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:54:04 by achu              #+#    #+#             */
/*   Updated: 2025/03/11 02:39:28 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Return true if the entire stack is sorted
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

// Return true if the first from stack b is valid to be placed first of stack a
int	is_valid(t_list *a, t_list *b)
{
	if (a->previous->nb < b->nb && b->nb < a->nb)
		return (1);
	return (0);
}

// Return true if the nb from a stack index is found
int	is_found(t_list *a, int find)
{
	if (a->nb == find)
		return (1);
	return (0);
}

// Return true if the nb from a stack is still under a max value
// Return false if no more nb can be found under the threshold
int	is_undermax(t_list *stack, int max)
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
