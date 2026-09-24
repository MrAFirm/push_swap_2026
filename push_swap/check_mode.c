/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:43:25 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/16 15:43:25 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_mode(char **av)
{
	if (ft_strncmp(av[1], "--bench", 8) == 0)
	//ft_bench
		return (0);
	else if (ft_strncmp(av[1], "--adaptive", 11) == 0
		|| ft_strncmp(av[2], "--adaptive", 11) == 0)
		return (4);
	else if (ft_strncmp(av[1], "--simple", 9) == 0
		|| ft_strncmp(av[2], "--simple", 9) == 0)
		return (1);
	else if (ft_strncmp(av[1], "--medium", 9) == 0
		|| ft_strncmp(av[2], "--medium", 9) == 0)
		return (2);
	else if (ft_strncmp(av[1], "--complex", 10) == 0
		|| ft_strncmp(av[2], "--complex", 10) == 0)
		return (3);
	return (4);
}

void	algo_select(char **av, t_list *a)
{
	t_stack_a	stack_a;
	t_stack_b	stack_b;
	t_list		*b;

	stack_a.top = a;
	stack_b.top = NULL;
	if (check_mode(av) == 1)
		range_sort_algo_sim(&stack_a, &stack_b);
	else if (check_mode(av) == 2)
		range_sort_algo(&stack_a, &stack_b);
	else if (check_mode(av) == 3)
	{
		a = stack_a.top;
		b = stack_b.top;
		index_stack(a);
		radix(&a, &b);
	}
	else if (check_mode(av) == 4)
		custom_adapt_algo(&stack_a, &stack_b);
	ft_lstclear(&a, del);
}
