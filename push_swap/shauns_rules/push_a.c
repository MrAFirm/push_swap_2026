/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 17:07:15 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/09 17:08:07 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack_a *stack_a, t_stack_b *stack_b)
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
	write(1, "pa\n", 3);
}
