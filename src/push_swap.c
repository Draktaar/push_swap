/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:10:38 by achu              #+#    #+#             */
/*   Updated: 2024/11/25 14:10:39 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printlist(t_list *stack)
{
	t_list	*temp;
	
	temp = stack;
	printf(" %d\n", temp->nb);
	temp = temp->next;
	while (temp != stack)
	{
		printf(" %d\n", temp->nb);
		temp = temp->next;
	}
}

void	rprintlist(t_list *stack)
{
	t_list	*temp;
	
	temp = stack;
	temp = temp->previous;
	while (temp != stack)
	{
		printf(" %d\n", temp->nb);
		temp = temp->previous;
	}
	printf(" %d\n", temp->nb);
}

int	is_digit(char *str)
{
	int		i;
	char	*max;
	int		num;

	i = 0;
	max = "2147483647";
	while (str[i])
	{
		if (str[i] == '-')
			max = "-2147483648";
		if (!('0' <= str[i] && str[i] <= '9') || !(str[i] == '-'))
			return (0);
		i++;
	}
	while (*str && i > 10)
	{
		if (*str > *max)
			return (0);
	}
	num = ft_atoi(str);
	return (num);
}

void	ft_init(t_list **stack, char *str)
{
	t_list	*temp;
	t_list	*prev;
	t_list	*loop;
	char	**tab;                         
	int		i;

	i = 0;
	prev = NULL;
	tab = ft_split(str, ' ');
	if (!tab)
		return (free(tab));
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

int	main(int argc, char **argv)
{
	char	**num;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc != 2 || !argv[1])
		return (write(1, "Error\n", 6), 1);
	ft_init(&a, argv[1]);
	if (!a)
		return (ft_lstclear(&a), 0);
	while (!is_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a);
		else if (ft_lstsize(a) == 3)
			ft_threesort(&a);
		else if (ft_lstsize(a) <= 5)
			ft_fivesort(&a, &b);
	}
	printlist(a);
	ft_lstclear(&a);
	return (0);
}
