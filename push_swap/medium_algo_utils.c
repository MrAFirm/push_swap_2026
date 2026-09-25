/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:50:57 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/25 16:25:22 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_range(t_stack_a *a, t_stack_b *b, int range_start, int range_end)
{
	int		iter;

	iter = range_start;
	while (iter <= range_end)
	{
		if (range_end == 0 && range_start == 0 && a->top->index == 0 && !a->top->next)
		{
			push_b(a, b);
			iter++;
		}
		else
		{
			if (a->top->index >= range_start && a->top->index <= range_end)
			{
				push_b(a, b);
				iter++;
				// if (b->top && b->top->next
				// 	&& b->top->index < b->top->next->index)
    			// 	swap_b(b);
			}
			else
				rotate_a(a);
		}
	}
}

int	*next_range_start(int range_start, int range_end, int blocksize)
{
	int	*start_end_arr;

	start_end_arr = ft_calloc(2, sizeof(int));
	if (!start_end_arr)
		return (start_end_arr);
	range_start -= blocksize;
	if (range_start < 0)
		range_start = 0;
	range_end -= blocksize;
	if (range_end < 0)
		range_end = 0;
	start_end_arr[0] = range_start;
	start_end_arr[1] = range_end;
	return (start_end_arr);
}

int	size_stack_a(t_stack_a *stack_a, int size)
{
	t_list	*head;

	head = stack_a->top;
	size = (int)ft_lstsize(head);
	return (size);
}

void	coords_compress(t_stack_a *stack_a)
{
	t_list			*head;
	unsigned int	size;
	int				manual_i;
	int				i;
	int				*winner;

	head = stack_a->top;
	size = ft_lstsize(head);
	manual_i = 0;
	i = 0;
	winner = ft_calloc(size, (sizeof(int)));
	if (!winner)
		return ;
	while ((unsigned int)i < size)
	{
		stack_a->top = head;
		check_smallest(stack_a, head, manual_i, winner);
		stack_a->top->index = manual_i;
		manual_i++;
		i++;
	}
	stack_a->top = head;
}

void	check_smallest(t_stack_a *stack_a, t_list *head, int manual_i, int *winner)
{
	int		match_flag;
	int		k;
	int		smallest;

	smallest = 2147483647;
	while (stack_a->top)
	{
		match_flag = 0;
		k = 0;
		while (k < manual_i)
		{
			if (winner[k] == stack_a->top->content)
				match_flag = 1;
			k++;
		}
		if (match_flag == 0 && smallest > stack_a->top->content)
			smallest = stack_a->top->content;
		stack_a->top = stack_a->top->next;
	}
	winner[manual_i] = smallest;
	stack_a->top = head;
	while (stack_a->top->content != smallest)
		stack_a->top = stack_a->top->next;
}
