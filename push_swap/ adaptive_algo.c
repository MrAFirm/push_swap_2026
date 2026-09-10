/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    adaptive_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:37:43 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/10 18:31:06 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	custom_adapt_algo(char *argv, t_stack_a *stack_a, t_stack_b *stack_b)
{
	size_t	i;
	float	disorder;

	i = 0;
	disorder = 0.0;
	if (argv[i] == "--adaptive")
	{
		disorder = compute_disorder(&stack_a);
		if (disorder < 0.2 || ft_lstsize(stack_a->top) <= 5)
			bubble_sort(stack_a);
		else if (disorder >= 0.2 && disorder < 0.5)
			range_sort_algo(stack_a, stack_b);
		else if (disorder >= 0.5)
			radix_sort(stack_a);
	}
}
