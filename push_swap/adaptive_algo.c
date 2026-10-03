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

void	custom_adapt_algo(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *be)
{
	float	disorder;
	t_list	*a;
	t_list	*b;

	disorder = 0.0;
	a = stack_a->top;
	b = stack_b->top;
	disorder = compute_disorder(stack_a);
	if (disorder == 0)
		return ;
	else if (ft_lstsize(stack_a->top) == 3)
		sort_3(stack_a, be);
	else if (ft_lstsize(stack_a->top) == 5)
		sort_5(stack_a, stack_b, be);
	else if (disorder < 0.2)
		bubble_sort(stack_a, be);
	else if (disorder >= 0.2 && disorder < 0.5)
		range_sort_algo(stack_a, stack_b, be);
	else if (disorder >= 0.5)
	{
		index_stack(a);
		radix(&a, &b, be);
		free(b);
	}
}
