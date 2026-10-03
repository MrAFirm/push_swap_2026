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

static void	sort3helper(t_stack_a *stack_a, t_bench *bench, t_list *c)
{
	if (c->content > c->next->content
		&& c->content > c->next->next->content
		&& c->next->content < c->next->next->content)
		rotate_a(stack_a, bench);
	else if (c->content < c->next->content
		&& c->content > c->next->next->content
		&& c->next->content > c->next->next->content)
		rrotate_a(stack_a, bench);
	else if (c->content < c->next->content
		&& c->content < c->next->next->content
		&& c->next->content > c->next->next->content)
	{
		rrotate_a(stack_a, bench);
		swap_a(stack_a, bench);
	}
}

void	sort_3(t_stack_a *stack_a, t_bench *bench)
{
	t_list	*c;

	c = stack_a->top;
	if (c->content > c->next->content && c->content > c->next->next->content
		&& c->next->content > c->next->next->content)
	{
		rotate_a(stack_a, bench);
		swap_a(stack_a, bench);
	}
	else if (c->content > c->next->content
		&& c->content < c->next->next->content
		&& c->next->content < c->next->next->content)
		swap_a(stack_a, bench);
	else
		sort3helper(stack_a, bench, c);
}

void	sort_5(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench)
{
	size_t	i;

	i = 0;
	coords_compress(stack_a);
	while (!stack_b->top || !stack_b->top->next)
	{
		if (stack_a->top->index == 1)
			push_b(stack_a, stack_b, bench);
		if (stack_a->top->index == 0)
			push_b(stack_a, stack_b, bench);
		if (stack_b->top && stack_b->top->next
			&& stack_b->top->index < stack_b->top->next->index)
			swap_b(stack_b, bench);
		rotate_a(stack_a, bench);
		i++;
	}
	sort_3(stack_a, bench);
	while (stack_b->top)
		push_a(stack_a, stack_b, bench);
}
