/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:10:38 by achu              #+#    #+#             */
/*   Updated: 2024/12/06 00:51:51 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	rprintlist(t_list *stack)
{
	t_list	*temp;
	
	temp = stack;
	while (temp->previous != stack)
	{
		temp = temp->previous;
		printf(" %d\n", temp->nb);
	}
	temp = temp->previous;
	printf(" %d\n", temp->nb);
}

static int	is_digit(char *str)
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

static void	ft_init(t_list **stack, char *str)
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

static void	ft_test(t_list **stack, char **argv)
{
	int	i;
	t_list	*loop;
	t_list	*temp;
	t_list	*prev;

	i = 0;
	prev = NULL;
	while (argv[i])
	{
		temp = ft_lstnew(ft_atoi(argv[i]));
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

int	main(int argc, char **argv)
{
	int		size;
	char	**num;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	// if (argc != 2 || !argv[1])
	// 	return (write(1, "Error\n", 6), 1);
	//ft_init(&a, argv[1]);
	ft_test(&a, argv);
	if (!a)
		return (ft_lstclear(&a), 0);
	size = ft_lstsize(a);
	if (size <= 5)
		ft_minisort(&a, &b);
	else
		ft_pushswap(&a, &b);
	ft_lstclear(&a);
	return (0);
}
