/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_med_sim_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:46:14 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/30 00:52:14 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack_a *stack_a, t_bench *bench)
{
	int	temp;

	temp = stack_a->top->content;
	stack_a->top->content = stack_a->top->next->content;
	stack_a->top->next->content = temp;
	if (stack_a->value->flag == 1)
		write(1, "sa\n", 3);
	bench->sa += 1;
	bench->total_ops += 1;
}

void	swap_b(t_stack_b *stack_b, t_bench *bench)
{
	int	temp;

	temp = stack_b->top->content;
	stack_b->top->content = stack_b->top->next->content;
	stack_b->top->next->content = temp;
	if (stack_b->value->flag == 1)
		write(1, "sb\n", 3);
	bench->sb += 1;
	bench->total_ops += 1;
}

void	rotate_a(t_stack_a *stack_a, t_bench *bench)
{
	t_list	*current;
	t_list	*next;
	t_list	*lst;

	if (!stack_a->top || !stack_a->top->next)
		return ;
	current = stack_a->top;
	next = stack_a->top->next;
	lst = ft_lstlast(stack_a->top);
	lst->next = current;
	current->next = NULL;
	stack_a->top = next;
	if (stack_a->value->flag == 1)
		write(1, "ra\n", 3);
	bench->ra += 1;
	bench->total_ops += 1;
}

void	rotate_b(t_stack_b *stack_b, t_bench *bench)
{
	t_list	*current;
	t_list	*next;
	t_list	*lst;

	if (!stack_b->top || !stack_b->top->next)
		return ;
	current = stack_b->top;
	next = stack_b->top->next;
	lst = ft_lstlast(stack_b->top);
	lst->next = current;
	current->next = NULL;
	stack_b->top = next;
	if (stack_b->value->flag == 1)
		write(1, "rb\n", 3);
	bench->rb += 1;
	bench->total_ops += 1;
}
