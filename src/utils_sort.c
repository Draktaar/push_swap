/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:54:04 by achu              #+#    #+#             */
/*   Updated: 2024/11/29 15:54:06 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*temp;
	t_list	*list;

	temp = stack->next;
	while (temp != stack)
	{
		if (temp->nb < temp->previous->nb)
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

int	get_top(t_list *a, t_list *b)
{
	int		i;
	int		j;
	t_list	*prv;
	t_list	*nxt;

	i = 0;
	j = 0;
	prv = a;
	nxt = a;
	while (prv->next)
		prv = prv->next;
	while (prv->previous)
	{
		prv = prv->previous;
		j++;
	}
	return (i);
}
