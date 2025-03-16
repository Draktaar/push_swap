/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:55:51 by achu              #+#    #+#             */
/*   Updated: 2025/03/16 21:09:46 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	do_raorra(a, ft_findmin(*a));
	pb(a, b, 1);
	do_raorra(a, ft_findmin(*a));
	pb(a, b, 1);
	ft_three(a);
	pa(a, b, 1);
	pa(a, b, 1);
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
