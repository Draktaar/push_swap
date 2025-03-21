/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:11:12 by achu              #+#    #+#             */
/*   Updated: 2025/03/21 12:10:11 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid(t_list **a, t_list **b, char *input)
{
	if (ft_strncmp(input, "sa\n", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(input, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(input, "ss\n", 3) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(input, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(input, "pb\n", 3) == 0)
		pb(a, b, 0);
	else if (ft_strncmp(input, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(input, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(input, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(input, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(input, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(input, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

static void	ft_check(t_list **a, t_list **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!is_valid(a, b, line))
		{
			error("Error");
			free(line);
			get_next_line(-1);
			return ;
		}
		free(line);
	}
	if (is_sorted(*a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	if (!ft_init(&a, argc, argv))
		return (ft_stack_clear(&a), error("Error"), 1);
	ft_check(&a, &b);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}
