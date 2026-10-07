/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo_selection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:19:02 by likhye-y          #+#    #+#             */
/*   Updated: 2026/10/07 17:20:30 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_select_algo(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench)
{
	int	blocksize;
	int	i;

	blocksize = 7;
	coords_compress(stack_a);
	i = 0;
	while (stack_a->top)
	{
		if (stack_a->top->index <= i)
		{
			push_b(stack_a, stack_b, bench);
			rotate_b(stack_b, bench);
			i++;
		}
		else if (stack_a->top->index <= i + blocksize)
		{
			push_b(stack_a, stack_b, bench);
			i++;
		}
		else
			rotate_a(stack_a, bench);
	}
	drain_b_to_a(stack_a, stack_b, bench);
}
