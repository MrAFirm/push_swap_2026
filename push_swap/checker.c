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

void	check(t_stack_a *stack_a, t_stack_b *stack_b)
{
	float	disorder;

	disorder = 0.0;
	disorder = compute_disorder(stack_a);
	if (stack_a->value->flag == 0)
	{
		if ((!stack_b->top && disorder == 0))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free(stack_a->value);
	ft_lstclear(&stack_a->top, del);
	if (stack_b->top)
		ft_lstclear(&stack_b->top, del);
}

static int	main_help(t_stack_a stack_a)
{
	t_stack_b	b;
	t_bench		*bench;

	stack_a.value = malloc(sizeof(*stack_a.value));
	if (free_check_1(stack_a.value) == -1)
		return (-1);
	b.value = malloc(sizeof(*b.value));
	if (free_check_2(stack_a.value, b.value) == -1)
		return (-1);
	bench = malloc(sizeof(t_bench));
	if (free_check_3(stack_a.value, b.value, bench) == -1)
		return (-1);
	stack_a.value->flag = 0;
	init_bench(bench, &stack_a);
	manual_sort(&stack_a, &b, bench);
	free(b.value);
	return (0);
}

int	main(int ac, char **av)
{
	t_list		*a;
	t_stack_a	stack_a;

	if (ac <= 1)
		return (0);
	a = NULL;
	if (!parsing_create(ac, av, &a) || !a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a.top = a;
	if (main_help(stack_a) == -1)
		return (-1);
	return (0);
}
