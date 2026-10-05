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

static int	check_mode(char **av, t_bench *bench)
{
	if (ft_strncmp(av[1], "--bench", 8) == 0
		|| ft_strncmp(av[2], "--bench", 8) == 0)
		bench->enabled = 1;
	if (ft_strncmp(av[1], "--adaptive", 11) == 0
		|| ft_strncmp(av[2], "--adaptive", 11) == 0)
		return (4);
	else if (ft_strncmp(av[1], "--simple", 9) == 0
		|| ft_strncmp(av[2], "--simple", 9) == 0)
		return (bench->strategy = 1, 1);
	else if (ft_strncmp(av[1], "--medium", 9) == 0
		|| ft_strncmp(av[2], "--medium", 9) == 0)
		return (bench->strategy = 2, 2);
	else if (ft_strncmp(av[1], "--complex", 10) == 0
		|| ft_strncmp(av[2], "--complex", 10) == 0)
		return (bench->strategy = 3, 3);
	return (4);
}

static void	complex_help(t_stack_b *s_b, t_bench *be, t_stack_a *s_a)
{
	index_stack(s_a->top);
	radix(&s_a->top, &s_b->top, be);
	if (s_b->top)
		ft_lstclear(&s_b->top, del);
}

void	algo_help(char **av, t_stack_a stack_a, t_bench *bench)
{
	t_stack_b	stack_b;

	stack_b.top = NULL;
	stack_b.value = malloc(sizeof(*stack_b.value));
	if (!stack_b.value)
	{
		ft_lstclear(&stack_a.top, del);
		return ;
	}
	stack_b.value->flag = 1;
	if (check_mode(av, bench) == 1)
		bubble_sort(&stack_a, bench);
	else if (check_mode(av, bench) == 2)
		range_sort_algo(&stack_a, &stack_b, bench);
	else if (check_mode(av, bench) == 3)
		complex_help(&stack_b, bench, &stack_a);
	else if (check_mode(av, bench) == 4)
		custom_adapt_algo(&stack_a, &stack_b, bench);
	free(stack_a.value);
	free(stack_b.value);
	if (stack_a.top)
		ft_lstclear(&stack_a.top, del);
	if (stack_b.top)
		ft_lstclear(&stack_b.top, del);
}

void	algo_select(char **av, t_list *a)
{
	t_stack_a	stack_a;
	float		disorder;

	stack_a.top = a;
	disorder = 0.0;
	disorder = compute_disorder(&stack_a);
	if (disorder == 0)
	{
		if (stack_a.top)
			ft_lstclear(&stack_a.top, del);
		return ;
	}
	stack_a.value = malloc(sizeof(*stack_a.value));
	if (!stack_a.value)
		return ;
	stack_a.value->flag = 1;
	algo_mid(stack_a, av);
}
