/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 21:32:13 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/16 21:36:23 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_stack_a *stack_a)
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
	write(1, "rra\n", 4);
}

void	rrotate_b(t_stack_b *stack_b)
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
	write(1, "rra\n", 4);
}

void	swap_s(t_stack_a *stack_a, t_stack_b *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	write(1, "ss\n", 3);
}

void	rotate_r(t_stack_a *stack_a, t_stack_b *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	write(1, "rr\n", 3);
}

void	rrotate_r(t_stack_a *stack_a, t_stack_b *stack_b)
{
	rrotate_a(stack_a);
	rrotate_b(stack_b);
	write(1, "rrr\n", 4);
}
