/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:37:43 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/30 17:31:57 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adaptive_help(t_stack_a *s_a, t_stack_b *s_b, t_bench *be, float dis);

void	custom_adapt_algo(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *be)
{
	float	disorder;

	disorder = 0.0;
	disorder = compute_disorder(stack_a);
	if (disorder == 0)
		return ;
	else if (ft_lstsize(stack_a->top) == 3)
	{
		sort_3(stack_a, be);
		be->strategy = 7;
	}
	else if (ft_lstsize(stack_a->top) == 5)
	{
		sort_5(stack_a, stack_b, be);
		be->strategy = 7;
	}
	else
		adaptive_help(stack_a, stack_b, be, disorder);
}

static void	adaptive_help(t_stack_a *s_a, t_stack_b *s_b, t_bench *be, float dis)
{
	t_list	*a;
	t_list	*b;

	a = s_a->top;
	b = s_b->top;

	if (dis < 0.2)
	{
		simple_select_algo(s_a, s_b, be);
		be->strategy = 4;
	}
	else if (dis >= 0.2 && dis < 0.5)
	{
		range_sort_algo(s_a, s_b, be);
		be->strategy = 5;
	}
	else if (dis >= 0.5)
	{
		index_stack(a);
		radix(&a, &b, be);
		free(b);
		s_a->top = a;
		be->strategy = 6;
	}
}

void	algo_mid(t_stack_a stack_a, char **av)
{
	t_bench		*bench;

	bench = malloc(sizeof(t_bench));
	if (!bench)
	{
		free(stack_a.value);
		ft_lstclear(&stack_a.top, del);
		return ;
	}
	init_bench(bench, &stack_a);
	algo_help(av, stack_a, bench);
	print_bench(bench);
	if (bench->disorder)
		free(bench->disorder);
	free(bench);
}

void	adaptive_help_be(t_bench *bench)
{
	if (bench->strategy == 4)
		ft_putstr_fd("Adaptive / O(n^2)\n", 2);
	else if (bench->strategy == 5)
		ft_putstr_fd("Adaptive / O(n√n)\n", 2);
	else if (bench->strategy == 6)
		ft_putstr_fd("Adaptive / O(n log n)\n", 2);
	else if (bench->strategy == 7)
		ft_putstr_fd("Adaptive / O(n)\n", 2);
}
