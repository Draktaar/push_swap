/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:01:43 by achu              #+#    #+#             */
/*   Updated: 2025/03/15 10:06:26 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static int	is_digit(char *str)
//{
//	int		i;
//	char	*max;
//	int		num;

//	i = 0;
//	max = "2147483647";
//	while (str[i])
//	{
//		if (str[i] == '-')
//			max = "-2147483648";
//		if (!('0' <= str[i] && str[i] <= '9') || !(str[i] == '-'))
//			return (0);
//		i++;
//	}
//	while (*str && i > 10)
//	{
//		if (*str > *max)
//			return (0);
//	}
//	num = ft_atoi(str);
//	return (num);
//}

static int  is_dup()
{
    
}

static void	ft_init(t_list **stack, int ac, char **av)
{
	t_list	*temp;
	t_list	*prev;
	t_list	*loop;
	char	**tab;                         
	int		i;

	i = 0;
	prev = NULL;
	tab = ft_split(av[1], ' ');
	if (!tab)
		return ;
	while (tab[i] != 0)
	{
		temp = ft_lstnew(ft_atoi(tab[i]));
		temp->previous = prev;
		prev = temp;
		ft_lstadd_back(stack, temp);
		i++;
	}
	loop = *stack;
	while (loop->next)
		loop = loop->next;
	loop->next = (*stack);
	(*stack)->previous = loop;
	ft_clearsplit(tab);
}

void	ft_test(t_list **stack, char **av)
{
	t_list	*loop;
	t_list	*temp;
	t_list	*prev;
	int	i;

	i = 0;
	prev = NULL;
	while (av[i])
	{
		temp = ft_lstnew(ft_atoi(av[i]));
		temp->previous = prev;
		prev = temp;
		ft_lstadd_back(stack, temp);
		i++;
	}
	loop = *stack;
	while (loop->next)
		loop = loop->next;
	loop->next = (*stack);
	(*stack)->previous = loop;
}
