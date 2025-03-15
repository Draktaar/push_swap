/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:06:47 by achu              #+#    #+#             */
/*   Updated: 2025/03/15 17:12:38 by achu             ###   ########.fr       */
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

void	ft_stack_addback(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	list = *lst;
	while (list->next)
		list = list->next;
	list->next = new;
}

int	ft_stack_size(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 1;
	temp = lst;
	while (temp->next != lst)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_stack_clear(t_list **lst)
{
	t_list	*list;
	t_list	*temp;

	if (lst || *lst)
	{
		temp = (*lst)->next;
		while (temp && (temp != *lst))
		{
			list = temp;
			temp = temp->next;
			free(list);
		}
		free(*lst);
		*lst = NULL;
	}
}
