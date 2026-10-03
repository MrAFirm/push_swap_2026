/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_med_sim_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 17:20:50 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/30 01:01:30 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench)
{
	t_list		*current;
	t_list		*next_head;

	if (!stack_b || !stack_b->top)
		return ;
	current = stack_b->top;
	next_head = stack_b->top->next;
	current->next = NULL;
	ft_lstadd_front(&stack_a->top, current);
	stack_b->top = next_head;
	if (stack_b->value->flag == 1)
		write(1, "pa\n", 3);
	bench->pa += 1;
	bench->total_ops += 1;
}

void	push_b(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench)
{
	t_list		*current;
	t_list		*next_head;

	if (!stack_a || !stack_a->top)
		return ;
	current = stack_a->top;
	next_head = stack_a->top->next;
	current->next = NULL;
	ft_lstadd_front(&stack_b->top, current);
	stack_a->top = next_head;
	if (stack_a->value->flag == 1)
		write(1, "pb\n", 3);
	bench->pb += 1;
	bench->total_ops += 1;
}
