/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:26:14 by achu              #+#    #+#             */
/*   Updated: 2024/12/06 14:26:15 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rborrb(t_list **stack, int step)
{
	int	i;

	i = step;
	while (i != 0)
	{
		if (i < 0)
		{
			rrb(stack);
			i++;
		}
		else
		{
			rb(stack);
			i--;
		}
	}
}

int	is_brobrr(t_list *a, t_list *b, int min, int max)
{
	int		i;
	int		step;
	int		low;
	t_list	*prv;
	t_list	*nxt;

	i = 0;
	step = 0;
	low = get_aroarr(a, b, min, max);
	prv = b;
	nxt = b;
	while (i < 10)
	{
		if (ft_abs(get_aroarr(a, prv, min, max)) < low)
		{
			low = ft_abs(get_aroarr(a, prv, min, max));
			step = -i;
		}
		if (ft_abs(get_aroarr(a, nxt, min, max)) < low)
		{
			low = ft_abs(get_aroarr(a, nxt, min, max));
			step = i;
		}
		prv = prv->previous;
		nxt = nxt->next;
		i++;
	}
	return (step);
}
