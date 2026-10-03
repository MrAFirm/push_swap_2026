/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 15:36:49 by amlee             #+#    #+#             */
/*   Updated: 2026/09/30 22:10:58 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free(stack_a->value);
}

int	main(int ac, char **av)
{
	t_list		*a;
	t_stack_a	stack_a;
	t_stack_b	b;
	t_bench		*bench;

	if (ac <= 1)
		return (0);
	a = NULL;
	if (!parsing_create(ac, av, &a) || !a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a.top = a;
	stack_a.value = malloc(sizeof(*stack_a.value));
	b.value = malloc(sizeof(*b.value));
	bench = malloc(sizeof(t_bench));
	if (!stack_a.value || !bench || !b.value)
		return (-1);
	stack_a.value->flag = 0;
	init_bench(bench, &stack_a);
	manual_sort(&stack_a, &b, bench);
	stack_a.top = a;
	ft_lstclear(&stack_a.top, del);
	if (b.top)
		ft_lstclear(&b.top, del);
	return (0);
}
