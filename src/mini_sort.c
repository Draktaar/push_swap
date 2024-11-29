/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:55:51 by achu              #+#    #+#             */
/*   Updated: 2024/11/27 11:55:52 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_threesort(t_list **stack)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack)->nb;
	mid = (*stack)->next->nb;
	bot = (*stack)->next->next->nb;
	if (top > mid && mid < bot && top < bot)
		sa(stack);
	else if (top > mid && mid > bot && top > bot)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(stack);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(stack);
		ra(stack);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(stack);
}

void	ft_fivesort(t_list **a, t_list **b)
{
	pb(a, b);
	pb(a, b);
	ft_threesort(a);
	while ((*b))
	{
		if ((*a)->nb < (*b)->nb)
			pa(a, b);
		else
			ra(a);
	}
}
