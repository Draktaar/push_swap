/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:54:04 by achu              #+#    #+#             */
/*   Updated: 2025/03/16 17:13:20 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Print the entire stack
void	printlist(t_list *stack)
{
	t_list	*temp;

	if (!stack)
		return ;
	temp = stack;
	while (temp->next != stack)
	{
		ft_printf(" %d\n", temp->nb);
		temp = temp->next;
	}
	ft_printf(" %d\n", temp->nb);
	ft_printf("---\n");
}

// Return true if the entire stack is sorted
int	is_sorted(t_list *stack)
{
	t_list	*temp;

	if (!stack)
		return (0);
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
static int	ft_posstep(t_list *stack)
{
	int		step;
	t_list	*temp;

	step = 0;
	temp = stack;
	while (temp->nb != get_max(stack))
	{
		temp = temp->next;
		step++;
	}
	return (step);
}

// Search form right to left of stack a number, and return the number of step 
static int	ft_negstep(t_list *stack)
{
	int		step;
	t_list	*temp;

	step = 0;
	temp = stack;
	while (temp->nb != get_max(stack))
	{
		temp = temp->previous;
		step--;
	}
	return (step);
}

// Return the smallest step to take to find that number
int	ft_findmax(t_list *stack)
{
	int	pos;
	int	neg;
	int	step;

	pos = ft_posstep(stack);
	neg = ft_negstep(stack);
	step = ft_mincmp(pos, neg);
	return (step);
}
