/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:06:47 by achu              #+#    #+#             */
/*   Updated: 2025/03/15 18:28:57 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_stack_new(int content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->nb = content;
	list->previous = NULL;
	list->next = NULL;
	return (list);
}

void	ft_stack_addback(t_list **stack, t_list *new)
{
	t_list	*list;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	list = *stack;
	while (list->next)
		list = list->next;
	list->next = new;
}

int	ft_stack_size(t_list *stack)
{
	int		i;
	t_list	*temp;

	i = 1;
	temp = stack;
	while (temp->next != stack)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_stack_clear(t_list **stack)
{
	t_list	*list;
	t_list	*temp;

	if (!stack || !*stack)
		return ;
	temp = (*stack)->next;
	while (temp && temp != *stack)
	{
		list = temp;
		temp = temp->next;
		free(list);
	}
	free(*stack);
	*stack = NULL;
}
