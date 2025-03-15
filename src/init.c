/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:01:43 by achu              #+#    #+#             */
/*   Updated: 2025/03/15 15:37:45 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_num(char *str)
{
	int		i;
	int		num;

	i = 0;
	num = ft_atoi(str);
	return (num);
}

static int  is_dup(t_list **stack)
{
    
}

static void	ft_init_split(t_list **stack, char *str)
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
		return ;
	while (tab[i])
	{
		temp = ft_stack_new(ft_atoi(tab[i]));
		temp->previous = prev;
		prev = temp;
		ft_stack_addback(stack, temp);
		i++;
	}
	loop = *stack;
	while (loop->next)
		loop = loop->next;
	loop->next = (*stack);
	(*stack)->previous = loop;
	ft_clear_dbl(tab);
}

static void	ft_init_argv(t_list **stack, char **argv)
{
	t_list	*temp;
	t_list	*loop;
	t_list	*prev;
	int	i;

	i = 1;
	prev = NULL;
	while (argv[i])
	{
		temp = ft_stack_new(ft_atoi(argv[i]));
		temp->previous = prev;
		prev = temp;
		ft_stack_addback(stack, temp);
		i++;
	}
	loop = *stack;
	while (loop->next)
		loop = loop->next;
	loop->next = (*stack);
	(*stack)->previous = loop;
}

int	ft_init(t_list **stack, int ac, char **av)
{
	if (ac <= 1)
		return (0);
	else if (ac == 2)
		ft_init_split(stack, av[1]);
	else
		ft_init_argv(stack, av);
	return (0);
}
