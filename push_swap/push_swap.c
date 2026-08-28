/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:08:33 by likhye-y          #+#    #+#             */
/*   Updated: 2026/08/28 17:24:00 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
	t_stack_a	stack_a;
	t_list	*head = NULL;
	t_list	*current;
	t_list	*new = ft_lstnew(2);
	t_list	*new2 = ft_lstnew(3);
	t_list	*new3 = ft_lstnew(1);
	
	ft_lstadd_front(&head, new3);
	ft_lstadd_front(&head, new2);
	ft_lstadd_front(&head, new);
	stack_a.top = head;
	bubble_sort(&stack_a);
	
	current = head;
	while (current)
	{
		printf("%i\n", current->content);
		current = current->next;
	}
}