/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:54:04 by achu              #+#    #+#             */
/*   Updated: 2024/12/05 18:29:57 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*temp;
	t_list	*list;

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

int	is_min(int a, int b)
{
	int	temp_a;
	int	temp_b;

	temp_a = a;
	temp_b = b;
	if (temp_a < 0)
		temp_a = -a;
	if (temp_b < 0)
		temp_b = -b;
	if (temp_a < temp_b)
		return (a);
	else
		return (b);
}

int	is_underchunk(t_list *stack, int max)
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

int	is_aroarr(t_list *a, t_list *b)
{
	int		i;
	int		j;
	t_list	*prv;
	t_list	*nxt;

	i = 0;
	j = 0;
	prv = a;
	nxt = a;
	while (!is_valid(prv, b) && prv->previous != a)
	{
		prv = prv->previous;
		i--;
	}
	while (!is_valid(nxt, b) && nxt->next != a)
	{
		nxt = nxt->next;
		j++;
	}
	return (is_min(i, j));
}

int	is_brobrr(t_list *a, t_list *b)
{
	int		i;
	int		min;
	int		step;
	t_list	*prv;
	t_list	*nxt;

	i = 0;
	step = 0;
	min = ft_abs(is_aroarr(a, b));
	prv = b;
	nxt = b;
	while (i < 5)
	{
		if (ft_abs(is_aroarr(a, prv)) < min)
		{
			min = ft_abs(is_aroarr(a, prv));
			step = -i;
		}
		if (ft_abs(is_aroarr(a, prv)) < min)
		{
			min = ft_abs(is_aroarr(a, prv));
			step = i;
		}
		prv = prv->previous;
		nxt = nxt->next;
		i++;
	}
	return (step);
}
