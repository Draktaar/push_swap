/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:01:43 by achu              #+#    #+#             */
/*   Updated: 2025/03/18 19:14:21 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_num(char *str);
int		is_limit(char *str);
int		is_dup(t_list *stack, int dup);

static int	is_valid(t_list *stack, char *str)
{
	int		nb;

	nb = ft_atoi(str);
	if (!is_num(str))
		return (0);
	else if (is_limit(str))
		return (0);
	else if (is_dup(stack, nb))
		return (0);
	return (1);
}

static int	ft_parse_stack(t_list **stack, char **tab)
{
	t_list	*temp;
	t_list	*prev;
	int		i;

	i = 0;
	prev = NULL;
	while (tab[i])
	{
		if (!is_valid(*stack, tab[i]))
			return (0);
		temp = ft_stack_new(ft_atoi(tab[i]));
		if (!temp)
			return (0);
		temp->previous = prev;
		prev = temp;
		ft_stack_addback(stack, temp);
		i++;
	}
	(*stack)->previous = temp;
	temp->next = (*stack);
	return (1);
}

int	ft_init(t_list **stack, int ac, char **av)
{
	char	**tab;

	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (!tab || !tab[0])
			return (0);
		if (!ft_parse_stack(stack, tab))
			return (ft_clear_dbl(tab), 0);
		ft_clear_dbl(tab);
	}
	else
	{
		if (!ft_parse_stack(stack, av + 1))
			return (0);
	}
	return (1);
}
