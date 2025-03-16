/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:26:14 by achu              #+#    #+#             */
/*   Updated: 2025/03/16 17:42:33 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Search form left to right of stack a number, and return the number of step 
static int	ft_fakerrb(t_list *a, t_list *b)
{
	int		step;
	t_list	*fa;
	t_list	*fb;

	step = 0;
	fa = a;
	fb = b;
	while (fb->nb < get_max(fb) && \
	fb->nb < fa->previous->nb && fa->previous->nb < get_max(fa))
	{
		rrb(&fb, 0);
		step--;
	}
	return (step);
}

// Search form right to left of stack a number, and return the number of step 
static int	ft_fakerb(t_list *a, t_list *b)
{
	int		step;
	t_list	*fa;
	t_list	*fb;

	step = 0;
	fa = a;
	fb = b;
	while (fb->nb < get_max(fb) && \
	fb->nb < fa->previous->nb && fa->previous->nb < get_max(fa))
	{
		rb(&fb, 0);
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

	pos = ft_fakerrb(a, b);
	neg = ft_fakerb(a, b);
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
			rrb(b, 1);
			i++;
		}
		else
		{
			rb(b, 1);
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
	pa(a, b, 1);
	while (*b)
	{
		while (get_max(*a) > (*a)->previous->nb && \
		(*a)->previous->nb > get_max(*b))
			rra(a, 1);
		do_rborrb(b, ft_algostep(*a, *b));
		pa(a, b, 1);
		if ((*b) && (*a)->nb < get_max(*b))
			ra(a, 1);
	}
	while (!is_sorted(*a))
		rra(a, 1);
}
