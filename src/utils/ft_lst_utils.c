/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:06:47 by achu              #+#    #+#             */
/*   Updated: 2025/03/11 02:17:08 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->nb = content;
	list->previous = 0;
	list->next = 0;
	return (list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!lst || !new)
		return ;
	list = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (list->next)
		list = list->next;
	list->next = new;
}

int	ft_lstsize(t_list *lst)
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

void	ft_lstclear(t_list **lst)
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
