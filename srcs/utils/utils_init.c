/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:56:38 by achu              #+#    #+#             */
/*   Updated: 2025/03/16 20:55:15 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '+' || str[i] == '-')
		i++;
	if (i >= 2)
		return (0);
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_limit(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 11 || (len == 11 &&  str[0] != '-'))
		return (1);
	else if (len == 11)
	{
		if (ft_strncmp(str, MININT, len) > 0)
			return (1);
	}
	else if (len == 10)
	{
		if (ft_strncmp(str, MAXINT, len) > 0)
			return (1);
	}
	return (0);
}

int	is_dup(t_list *stack, int dup)
{
	t_list	*temp;

	if (!stack)
		return (0);
	temp = stack;
	while (temp)
	{
		if (temp->nb == dup)
			return (1);
		temp = temp->next;
	}
	return (0);
}
