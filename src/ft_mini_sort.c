/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:55:51 by achu              #+#    #+#             */
/*   Updated: 2025/03/16 17:06:05 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Depends on the number of step to take
// Do rb if the step are positive 
// Do rrb if the step are negative 
static void	do_raorra(t_list **b, int step)
{
	int	i;

	i = step;
	while (i != 0)
	{
		if (i < 0)
		{
			rra(b, 1);
			i++;
		}
		else
		{
			ra(b, 1);
			i--;
		}
	}
}

static void	ft_three(t_list **stack)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack)->nb;
	mid = (*stack)->next->nb;
	bot = (*stack)->next->next->nb;
	if (top > mid && mid < bot && top < bot)
		sa(stack, 1);
	else if (top > mid && mid > bot && top > bot)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(stack, 1);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(stack, 1);
}

static void	ft_four(t_list **a, t_list **b)
{
	int	min;

	min = get_min(*a);
	while ((*a)->nb != min)
		ra(a, 1);
	pb(a, b, 1);
	ft_three(a);
	pa(a, b, 1);
}

static void	ft_five(t_list **a, t_list **b)
{
	do_raorra(a, ft_findmax(*a));
	pb(a, b, 1);
	do_raorra(a, ft_findmax(*a));
	pb(a, b, 1);
	ft_three(a);
	sb(b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	while (!is_sorted(*a))
		rra(a, 1);
}

void	ft_minisort(t_list **a, t_list **b)
{
	int	size;

	size = ft_stack_size(*a);
	if (!is_sorted(*a))
	{
		if (size == 2)
			sa(a, 1);
		else if (size == 3)
			ft_three(a);
		else if (size == 4)
			ft_four(a, b);
		else if (size == 5)
			ft_five(a, b);
	}
}
