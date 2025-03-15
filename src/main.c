/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:10:38 by achu              #+#    #+#             */
/*   Updated: 2025/03/14 17:17:55 by achu             ###   ########.fr       */
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
	if (argc <= 2)
		return ;
	//ft_init(&a, argv[1]);
	ft_test(&a, argv);
	if (!a)
		return (ft_lstclear(&a), 0);
	size = ft_lstsize(a);
	if (size <= 5)
		ft_minisort(&a, &b);
	else
		ft_sort(&a, &b);
	ft_lstclear(&a);
	return (0);
}
