/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 15:36:49 by amlee             #+#    #+#             */
/*   Updated: 2026/09/30 01:27:13 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	del(int content)
{
	(void)content;
}

void	check(t_stack_a *stack_a)
{
	float	disorder;
	
	disorder = 0.0;
	disorder = compute_disorder(stack_a);
	if (disorder == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_list		*a;
	t_stack_a	stack_a;

	if (ac <= 1)
		return (0);
	a = NULL;
	stack_a.top = a;
	if (!parsing_create(ac, av, &a) || !a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a.top = a;
	manual_sort(&stack_a);
	ft_lstclear(&a, del);
	return (0);
}
