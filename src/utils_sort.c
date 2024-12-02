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

int	get_minimum(t_list *stack)
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

int	get_maximum(t_list *stack)
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

int	is_min(int a, int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_perfect_spot(t_list *a, t_list *b)
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

int	ft_optimal_path(t_list **a, t_list **b)
{
	int		i;
	int		min;
	int		step;
	t_list	*prv;
	t_list	*nxt;

	i = 0;
	min = ft_perfect_spot(a, b);
	prv = *b;
	nxt = *b;
	while (i < 5)
	{
		if (ft_perfect_spot(a, prv) < min)
		{
			min = ft_perfect_spot(a, prv);
			step = -i;	
		}
		if (ft_perfect_spot(a, nxt) < min)
		{
			min = ft_perfect_spot(a, nxt);
			step = i;	
		}
		prv = prv->previous;
		nxt = nxt->next;
		i++;
	}
	return (step);
}

void	aroarr(t_list **a, t_list **b)
{
	
}