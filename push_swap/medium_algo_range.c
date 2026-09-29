/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 22:15:32 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/25 16:26:58 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	range_sort_algo(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench)
{
	int	blocksize;
	int	i;

	blocksize = block_size(stack_a);
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

int	find_max(t_stack_b *stack_b)
{
	t_list	*current;
	size_t	i;
	size_t	max_idx;
	size_t	max_pos;

	current = stack_b->top;
	i = 0;
	max_pos = i;
	max_idx = current->index;
	while (current)
	{
		if (current->index > (int)max_idx)
		{
			max_idx = current->index;
			max_pos = i;
		}
		current = current->next;
		i++;
	}
	return (max_pos);
}

static void	drain_help(t_stack_b *stack_b, t_bench *b, int size, int max_pos)
{
	int	i;

	i = 0;
	if (max_pos <= size / 2)
	{
		while (i < max_pos)
		{
			rotate_b(stack_b, b);
			i++;
		}
	}
	else if (max_pos > size / 2)
	{
		while (i < size - max_pos)
		{
			rrotate_b(stack_b, b);
			i++;
		}
	}
}

void	drain_b_to_a(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench)
{
	int	size;
	int	max_pos;

	while (stack_b->top)
	{
		size = (int)ft_lstsize(stack_b->top);
		max_pos = find_max(stack_b);
		drain_help(stack_b, bench, size, max_pos);
		push_a(stack_a, stack_b, bench);
	}
}
/*
k ≈ √n (Check notes) with custom sqrt function.
O(n√n)
*/

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}
