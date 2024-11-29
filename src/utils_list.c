/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:06:47 by achu              #+#    #+#             */
/*   Updated: 2024/11/25 15:06:47 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	t_list	*list;

	if (!lst)
		return (0);
	i = 1;
	list = lst;
	while (list->next)
	{
		list = list->next;
		i++;
	}
	return (i);
}

static void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	//free(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*list;

	if (!lst || !*lst)
		return ;
	list = *lst;
	while (lst && *lst)
	{
		list = (*lst)->next;
		ft_lstdelone((*lst));
		*lst = list;
	}
}
