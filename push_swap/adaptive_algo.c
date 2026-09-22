/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:37:43 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/22 18:27:16 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	custom_adapt_algo(t_stack_a *stack_a, t_stack_b *stack_b)
{
	size_t	i;
	float	disorder;
	t_list	*a;
	t_list	*b;

	i = 0;
	disorder = 0.0;
	a = stack_a->top;
	b = NULL;
	disorder = compute_disorder(stack_a);
	if (disorder < 0.2 || ft_lstsize(stack_a->top) <= 5)
		range_sort_algo_sim(stack_a, stack_b);
	else if (disorder >= 0.2 && disorder < 0.5)
		range_sort_algo(stack_a, stack_b);
	else if (disorder >= 0.5)
	{
		a = stack_a->top;
		index_stack(a);
		radix(&a, &b);
	}
}
