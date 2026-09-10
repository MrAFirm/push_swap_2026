/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo_bubble.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:37:37 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/07 19:05:58 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack_a *stack_a)
{
	size_t	i;
	size_t	j;
	t_list	*head;

	i = 0;
	head = stack_a->top;
	while (i < ft_lstsize(stack_a->top))
	{
		j = 0;
		while (j < ft_lstsize(stack_a->top) - i - 1)
		{
			if (stack_a->top->content > stack_a->top->next->content)
				swap_a(stack_a);
			rotate_a(stack_a);
			j++;
		}
		while (j < ft_lstsize(stack_a->top))
		{
			rotate_a(stack_a);
			j++;
		}
		i++;
	}
}

/*
int main()
{
	t_stack_a	stack_a;
	t_list	*head = NULL;
	t_list	*current;
	t_list	*next;
	// t_list	*new7 = ft_lstnew(6);
	// t_list	*new6 = ft_lstnew(4);
	t_list	*new5 = ft_lstnew(6);
	t_list	*new4 = ft_lstnew(4);
	t_list	*new3 = ft_lstnew(1);
	t_list	*new2 = ft_lstnew(9);
	t_list	*new = ft_lstnew(2);
	
	// ft_lstadd_front(&head, new7);
	// ft_lstadd_front(&head, new3);
	ft_lstadd_front(&head, new5);
	ft_lstadd_front(&head, new4);
	ft_lstadd_front(&head, new3);
	ft_lstadd_front(&head, new2);
	ft_lstadd_front(&head, new);
	stack_a.top = head;

	current = head;
	printf("Before: ");
	while (current)
	{
		printf("%d ", current->content);
		current = current->next;
	}

	bubble_sort(&stack_a);
	next = stack_a.top;
	printf("After: ");
	while (next)
	{
		printf("%d ", next->content);
		next = next->next;
	}
}
*/
