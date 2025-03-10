/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:55:51 by achu              #+#    #+#             */
/*   Updated: 2025/03/10 16:45:57 by achu             ###   ########.fr       */
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

static void	ft_four(t_list **a, t_list **b)
{
	int	min;

	min = get_min(*a);
	while ((*a)->nb != min)
		ra(a);
	pb(a, b);
	ft_three(a);
	pa(a, b);
}

static void	ft_five(t_list **a, t_list **b)
{
	int	min;
	int size;

	min = get_min(*a);
	pb(a, b);
	while ((*a)->nb != min)
		ra(a);
	pb(a, b);
	ft_three(a);
	pa(a, b);
	size = is_aroarr(*a, *b);
	while (size != 0)
	{
		if (size < 0)
		{
			rra(a);
			size++;
		}
		else
		{
			ra(a);
			size--;
		}
	}
	pa(a, b);
	while (!is_sorted(*a))
		ra(a);
}

void	ft_minisort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	printf("%i", size);
	if (!is_sorted(*a))
	{
		if (size == 2)
			sa(a);
		else if (size == 3)
			ft_three(a);
		else if (size == 4)
			ft_four(a, b);
		else if (size == 5)
			ft_five(a, b);
	}
}
