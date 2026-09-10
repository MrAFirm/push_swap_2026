/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:36:16 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/10 14:16:51 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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