/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:02:05 by achu              #+#    #+#             */
/*   Updated: 2024/11/25 15:02:05 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **a)
{
	t_list	*temp;

	temp = *a;
	temp = temp->next;
	*a = temp;
}

void	rb(t_list **b)
{
	t_list	*temp;

	temp = *b;
	temp = temp->next;
	*b = temp;
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
