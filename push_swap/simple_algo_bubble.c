/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo_bubble.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:37:37 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/22 18:55:51 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	range_sort_algo_sim(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int		size;
	int		range_start;
	int		range_end;
	int		blocksize;
	int		*arr;

	size = size_stack_a(stack_a, 0);
	blocksize = 7;
	coords_compress(stack_a);
	range_start = size - blocksize;
	if (range_start < 0)
		range_start = 0;
	range_end = size - 1;
	while (range_start >= 0)
	{
		push_range(stack_a, stack_b, range_start, range_end);
		if (stack_b->top)
			de_bubble_sort(stack_a, stack_b);
		if (range_start == 0)
			return ;
		if (range_start == 0 && range_end == 0)
			return ;
		arr = next_range_start(range_start, range_end, blocksize);
		range_start = arr[0];
		range_end = arr[1];
	}
}

/*
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
*/

/*
int main()
{
	t_stack_a	stack_a;
	t_list	*head = NULL;
	t_list	*current;
	t_list	*next;
	t_list	*new7 = ft_lstnew(6);
	t_list	*new6 = ft_lstnew(4);
	t_list	*new5 = ft_lstnew(6);
	t_list	*new4 = ft_lstnew(4);
	t_list	*new3 = ft_lstnew(1);
	t_list	*new2 = ft_lstnew(9);
	t_list	*new = ft_lstnew(2);
	
	ft_lstadd_front(&head, new7);
	ft_lstadd_front(&head, new3);
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
