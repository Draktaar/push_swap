/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:26:14 by achu              #+#    #+#             */
/*   Updated: 2025/03/15 18:58:06 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Search form left to right of stack a number, and return the number of step 
static int	ft_rrtalgo(t_list *a, t_list *b)
{
	int		step;
	t_list	*ta;
	t_list	*tb;

	step = 0;
	ta = a;
	tb = b;
	while (tb->nb < get_max(tb) && \
	tb->nb < ta->previous->nb && ta->previous->nb < get_max(ta))
	{
		rrt(&tb);
		step--;
	}
	return (step);
}

// Search form right to left of stack a number, and return the number of step 
static int	ft_rtalgo(t_list *a, t_list *b)
{
	int		step;
	t_list	*ta;
	t_list	*tb;

	step = 0;
	ta = a;
	tb = b;
	while (tb->nb < get_max(tb) && \
	tb->nb < ta->previous->nb && ta->previous->nb < get_max(ta))
	{
		rt(&tb);
		step++;
	}
	return (step);
}

// Return the smallest step to take to find that number
static int	ft_algostep(t_list *a, t_list *b)
{
	int	pos;
	int	neg;
	int	step;

	pos = ft_rrtalgo(a, b);
	neg = ft_rtalgo(a, b);
	step = ft_mincmp(pos, neg);
	return (step);
}

// Depends on the number of step to take
// Do rb if the step are positive 
// Do rrb if the step are negative 
static void	do_rborrb(t_list **b, int step)
{
	int	i;

	i = step;
	while (i != 0)
	{
		if (i < 0)
		{
			rrb(b);
			i++;
		}
		else
		{
			rb(b);
			i--;
		}
	}
}

void	ft_sort(t_list **a, t_list **b)
{
	int	size;

	size = 3;
	if (ft_stack_size(*a) > 200)
		size = 6;
	ft_divconq(a, b, size);
	do_rborrb(b, ft_findmax(*b));
	pa(a, b);
	while (*b)
	{
		while (get_max(*a) > (*a)->previous->nb && \
		(*a)->previous->nb > get_max(*b))
			rra(a);
		do_rborrb(b, ft_algostep(*a, *b));
		pa(a, b);
		if ((*b) && (*a)->nb < get_max(*b))
			ra(a);
	}
	while (!is_sorted(*a))
		rra(a);
}
