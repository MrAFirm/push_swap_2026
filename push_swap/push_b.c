/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 17:07:23 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/09 17:08:09 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack_a *stack_a, t_stack_b *stack_b)
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
	write(1, "pb\n", 3);

}