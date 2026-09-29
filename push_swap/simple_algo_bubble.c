/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo_bubble.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:37:37 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/29 16:33:12 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	bubble_helper(t_stack_a *a, t_list *top, t_bench *b, size_t i)
{
	size_t	j;
	size_t	count;

	j = 0;
	count = 0;
	while (j < ft_lstsize(top) - i - 1)
	{
		if (top->content > top->next->content)
		{
			swap_a(a, b);
			top = a->top;
			count = 1;
		}
		rotate_a(a, b);
		top = a->top;
		j++;
	}
	while (j < ft_lstsize(a->top))
	{
		rotate_a(a, b);
		top = a->top;
		j++;
	}
	return (count);
}

void	bubble_sort(t_stack_a *stack_a, t_bench *bench)
{
	size_t	i;
	size_t	count;

	i = 0;
	while (i < ft_lstsize(stack_a->top))
	{
		count = 0;
		count = bubble_helper(stack_a, stack_a->top, bench, i);
		if (count == 0)
			break ;
		i++;
	}
}
