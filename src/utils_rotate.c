/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:02:05 by achu              #+#    #+#             */
/*   Updated: 2024/12/03 20:26:15 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **a)
{
	t_list	*temp;

	if (!*a)
		return ;
	temp = *a;
	temp = temp->next;
	*a = temp;
}

void	rb(t_list **b)
{
	t_list	*temp;

	if (!*b)
		return ;
	temp = *b;
	temp = temp->next;
	*b = temp;
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
