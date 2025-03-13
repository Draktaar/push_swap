/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:54:04 by achu              #+#    #+#             */
/*   Updated: 2025/03/13 02:13:42 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Print the entire stack
void	printlist(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp->next != stack)
	{
		printf(" %d\n", temp->nb);
		temp = temp->next;
	}
	printf(" %d\n", temp->nb);
	printf("---\n");
}

// Return true if the entire stack is sorted
int	is_sorted(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp->next != stack)
	{
		if (temp->next->nb < temp->nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

// Search form left to right of stack a number, and return the number of step 
int	ft_posfind(t_list *stack, int find)
{
	int		step;
	t_list	*temp;

	step = 0;
	temp = stack;
	while (temp->next != stack)
	{
		if (temp->nb == find)
			return (step);
		temp = temp->next;
		step++;
	}
	return (0);
}

// Search form right to left of stack a number, and return the number of step 
int	ft_negfind(t_list *stack, int find)
{
	int		step;
	t_list	*temp;

	step = 0;
	temp = stack;
	while (temp->previous != stack)
	{
		if (temp->nb == find)
			return (step);
		temp = temp->previous;
		step--;
	}
	return (0);
}

// Return the smallest step to take to find that number
int	ft_finder(t_list *stack, int find)
{
	int	pos;
	int	neg;
	int	step;

	pos = ft_posfind(stack, find);
	neg = ft_negfind(stack, find);
	step = ft_mincmp(pos, neg);
	return (step);
}
