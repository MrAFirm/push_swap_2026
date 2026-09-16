/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_med_sim_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:46:14 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/16 17:21:39 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack_a *stack_a)
{
	int	temp;

	temp = stack_a->top->content;
	stack_a->top->content = stack_a->top->next->content;
	stack_a->top->next->content = temp;
    write(1, "sa\n", 3);
}

void	swap_b(t_stack_b *stack_b)
{
	int	temp;

	temp = stack_b->top->content;
	stack_b->top->content = stack_b->top->next->content;
	stack_b->top->next->content = temp;
    write(1, "sb\n", 3);
}

void	rotate_a(t_stack_a *stack_a)
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
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack_b *stack_b)
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
	write(1, "rb\n", 3);
}

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
