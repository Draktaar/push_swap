/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_asort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:48:43 by achu              #+#    #+#             */
/*   Updated: 2025/03/10 21:16:57 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Depends on the number of step to take
// Do ra if the step are positive 
// Do rra if the step are negative 
static void	do_raorra(t_list **stack, int step)
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
	while (!is_minamax(prv, find) && prv->previous != a)
	{
		prv = prv->previous;
		i--;
	}
	while (!is_minamax(nxt, find) && nxt->next != a)
	{
		nxt = nxt->next;
		j++;
	}
	return (ft_mincmp(i, j));
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
	return (ft_mincmp(i, j));
}

int	get_aroarr(t_list *a, t_list *b, int min, int max)
{
	int	i;

	if (b->nb < min)
		i = testaroarr(a, min);
	else if (max < b->nb)
		i = testaroarr(a, max) + 1;
	else
		i = is_aroarr(a, b);
	return (i);
}

void	ft_blabla(t_list **a, t_list **b, int *min, int *max)
{
	int	i;

	if ((*b)->nb < *min)
	{
		i = testaroarr(*a, *min);
		*min = (*b)->nb;
		do_raorra(a, i);
		pa(a, b);
	}
	else if ((*b)->nb > *max)
	{
		i = testaroarr(*a, *max);
		*max = (*b)->nb;
		do_raorra(a, i);
		ra(a);
		pa(a, b);
	}
	else
	{
		i = is_aroarr(*a, *b);
		do_raorra(a, i);
		pa(a, b);		
	}
}
