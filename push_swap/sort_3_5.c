/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:04:14 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/24 17:00:22 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack_a *stack_a)
{
	t_list  *current;

	current = stack_a->top;
	if (current->content > current->next->content
		&& current->content > current->next->next->content
		&& current->next->content > current->next->next->content)
		{
			rotate_a(stack_a);
			swap_a(stack_a);
		}
	else if (current->content > current->next->content
		&& current->content < current->next->next->content
		&& current->next->content < current->next->next->content)
		swap_a(stack_a);
	else if (current->content > current->next->content
		&& current->content > current->next->next->content
		&& current->next->content < current->next->next->content)
		rotate_a(stack_a);
	else if (current->content < current->next->content
		&& current->content > current->next->next->content
		&& current->next->content > current->next->next->content)
		rrotate_a(stack_a);
	else if (current->content < current->next->content
		&& current->content < current->next->next->content
		&& current->next->content > current->next->next->content)
		{
			rrotate_a(stack_a);
			swap_a(stack_a);
		}
}

void	sort_5(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_list	*current;
	size_t	i;

	current = stack_a->top;
	i = 0;
	coords_compress(stack_a);
	while (!stack_b->top || !stack_b->top->next)
	{
		if (stack_a->top->index == 1)
			push_b(stack_a, stack_b);
		if (stack_a->top->index == 0)
			push_b(stack_a, stack_b);
		if (stack_b->top && stack_b->top->next
			&& stack_b->top->index < stack_b->top->next->index)
			swap_b(stack_b);
		rotate_a(stack_a);
		i++;
	}
	sort_3(stack_a);
	while (stack_b->top)
		push_a(stack_a, stack_b);
}
