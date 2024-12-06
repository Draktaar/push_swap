/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:35:47 by achu              #+#    #+#             */
/*   Updated: 2024/12/06 01:14:47 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_initmedian(t_list **a, t_list **b)
{
	int min;
	int	size;

	min = get_min(*a);
	size = (ft_abs(min) + ft_abs(get_max(*a))) / 8;
	while (*a)
	{
		if (!is_inchunk((*a), min + size))
			min += size + 1;
		if ((*a)->nb <= min + size)
		{
			if ((*a)->nb <= min + size / 2)
				pb(a, b); 
			else
			{
				pb(a, b);
				rb(b);
			}
		}
		else
			ra(a);
	}
}

static int	is_findvalid(t_list *a, int find)
{
	if (a->nb == find)
		return (1);
	return (0);
}

static int	testaroarr(t_list *a, int find)
{
	int		i;
	int		j;
	t_list	*prv;
	t_list	*nxt;

	i = 0;
	j = 0;
	prv = a;
	nxt = a;
	while (!is_findvalid(prv, find) && prv->previous != a)
	{
		prv = prv->previous;
		i--;
	}
	while (!is_findvalid(nxt, find) && nxt->next != a)
	{
		nxt = nxt->next;
		j++;
	}
	return (is_min(i, j));
}

static void	rorr(t_list **stack, int step)
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

static void	ft_sort(t_list **a, t_list **b)
{
	int	min;
	int	max;
	int	step;

	step = 0;
	min = (*b)->nb;
	max = (*b)->nb;
	pa(a, b);
	while (*b)
	{
		if ((*b)->nb < min)
		{
			step = testaroarr(*a, min);
			min = (*b)->nb;
			rorr(a, step);
			pa(a, b);
		}
		else if ((*b)->nb > max)
		{
			step = testaroarr(*a, max);
			max = (*b)->nb;
			rorr(a, step);
			ra(a);
			pa(a, b);
		}
		else
		{
			step = is_aroarr(*a, *b);
			rorr(a, step);
			pa(a, b);		
		}
	}
}

void	ft_pushswap(t_list **a, t_list **b)
{
	ft_initmedian(a, b);
	ft_sort(a, b);
	//while (!is_sorted(*a))
	//	ra(a);
}
