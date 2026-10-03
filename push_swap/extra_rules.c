/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 21:32:13 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/30 00:54:18 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_stack_a *stack_a, t_bench *bench)
{
	t_list	*current;
	t_list	*prev;
	t_list	*lst;
	t_list	*last;

	lst = stack_a->top;
	last = ft_lstlast(stack_a->top);
	while (lst->next->next)
		lst = lst->next;
	prev = lst;
	prev->next = NULL;
	current = last;
	current->next = stack_a->top;
	stack_a->top = current;
	if (stack_a->value->flag == 1)
		write(1, "rra\n", 4);
	bench->rra += 1;
	bench->total_ops += 1;
}

void	rrotate_b(t_stack_b *stack_b, t_bench *bench)
{
	t_list	*current;
	t_list	*prev;
	t_list	*lst;
	t_list	*last;

	lst = stack_b->top;
	last = ft_lstlast(stack_b->top);
	while (lst->next->next)
		lst = lst->next;
	prev = lst;
	prev->next = NULL;
	current = last;
	current->next = stack_b->top;
	stack_b->top = current;
	if (stack_b->value->flag == 1)
		write(1, "rrb\n", 4);
	bench->rrb += 1;
	bench->total_ops += 1;
}

void	swap_s(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench)
{
	swap_a(stack_a, bench);
	swap_b(stack_b, bench);
	if (stack_a->value->flag == 1)
		write(1, "ss\n", 3);
	bench->ss += 1;
	bench->total_ops += 1;
}

void	rotate_r(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench)
{
	rotate_a(stack_a, bench);
	rotate_b(stack_b, bench);
	if (stack_a->value->flag == 1)
		write(1, "rr\n", 3);
	bench->rr += 1;
	bench->total_ops += 1;
}

void	rrotate_r(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench)
{
	rrotate_a(stack_a, bench);
	rrotate_b(stack_b, bench);
	if (stack_a->value->flag == 1)
		write(1, "rrr\n", 4);
	bench->rrr += 1;
	bench->total_ops += 1;
}
