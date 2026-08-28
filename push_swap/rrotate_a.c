/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 17:46:43 by likhye-y          #+#    #+#             */
/*   Updated: 2026/08/28 18:07:47 by likhye-y         ###   ########.fr       */
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
