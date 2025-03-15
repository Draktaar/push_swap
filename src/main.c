/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:10:38 by achu              #+#    #+#             */
/*   Updated: 2025/03/15 15:08:33 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		size;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	ft_init(&a, argc, argv);
	if (!a)
		return (ft_stack_clear(&a), 0);
	size = ft_stack_size(a);
	if (size <= 5)
		ft_minisort(&a, &b);
	else
		ft_sort(&a, &b);
	ft_stack_clear(&a);
	return (0);
}
