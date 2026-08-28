/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 21:41:04 by likhye-y          #+#    #+#             */
/*   Updated: 2026/08/28 17:25:29 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack_a *stack_a)
{
	t_list	*current;
	t_list	*next;
	t_list	*lst;

	current = stack_a->top;
	next = stack_a->top->next;
	lst = ft_lstlast(stack_a->top);
	lst->next = current;
	current->next = NULL;
	stack_a->top = next;
	write(1, "ra\n", 3);
}
