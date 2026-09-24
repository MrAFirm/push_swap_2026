/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 22:15:32 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/24 21:42:14 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	range_sort_algo(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int		size;
	int		range_start;
	int		range_end;
	int		blocksize;
	int		*arr;

	size = size_stack_a(stack_a, 0);
	blocksize = block_size(stack_a);
	coords_compress(stack_a);
	range_start = size - blocksize;
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
		free(arr);
	}
}

int	find_max(t_stack_b *stack_b)
{
	t_list	*current;
	size_t	i;
	size_t	max_idx;
	size_t	max_pos;

	current = stack_b->top;
	i = 0;
	while (current)
	{
		if (current->next)
			break ;
		if (current->index > current->next->index)
		{
			max_idx = current->index;
			max_pos = i;
		}
		current = current->next;
		i++;
	}
	return (max_pos);
}

void	drain_b_to_a(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	size;
	int	max_pos;
	int	i;

	while (stack_b->top)
	{
		size = (int)ft_lstsize(stack_b->top);
		max_pos = find_max(stack_b);
		i = 0;
		if (max_pos <= size / 2)
		{
			while (i < max_pos)
			{
				rotate_b(stack_b);
				i++;
			}
		}
		else if (max_pos >= size / 2)
		{
			while (i < size - max_pos)
			{
				rrotate_b(stack_b);
				i++;
			}
		}
		push_a(stack_a, stack_b);
	}
}

/*
void	de_bubble_sort(t_stack_a *stack_a, t_stack_b *stack_b)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	while (i < ft_lstsize(stack_b->top))
	{
		j = 0;
		count = 0;
		while (j < ft_lstsize(stack_b->top) - i - 1)
		{
			if (stack_b->top->content < stack_b->top->next->content)
			{
				swap_b(stack_b);
				count = 1;
			}
			rotate_b(stack_b);
			j++;
		}
		while (j < ft_lstsize(stack_b->top))
		{
			rotate_b(stack_b);
			j++;
		}
		if (count == 0)
			break ;
		i++;
	}
	while (stack_b->top)
		push_a(stack_a, stack_b);
}
*/

int	block_size(t_stack_a *stack_a)
{
	int	total_size;
	int	blocksize;

	total_size = ft_lstsize(stack_a->top);
	blocksize = ft_sqrt(total_size);
	return (blocksize);
}

/*
k ≈ √n (Check notes) with custom sqrt function.
O(n√n)
*/

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}

/*
static int	*coords_compress(t_stack_a *stack_a)
{
	t_list			*head;
	unsigned int	size;
	int				manual_i;
	int				i;
	int				smallest;
	int				*winner;
	int				k;
	int				match_flag;

	head = stack_a->top;
	size = ft_lstsize(head);
	manual_i = 0;
	i = 0;
	winner = ft_calloc(size, (sizeof(int)));
	if (!winner)
		return (NULL);
	while ((unsigned int)i < size)
	{
		smallest = 2147483647;
		stack_a->top = head;
		while (stack_a->top)
		{
			match_flag = 0;
			k = 0;
			while (k < manual_i)
			{
				if (winner[k] == stack_a->top->content)
					match_flag = 1;
				k++;
			}
			if (match_flag == 0)
			{
				if (smallest > stack_a->top->content)
					smallest = stack_a->top->content;
			}
			stack_a->top = stack_a->top->next;
		}
		winner[manual_i] = smallest;
		stack_a->top = head;
		while (stack_a->top->content != smallest)
		stack_a->top = stack_a->top->next;
		stack_a->top->index = manual_i;
		manual_i++;
		i++;
	}
	stack_a->top = head;
	return (winner);
}
O(n^2)
*/

/*
int main()
{
	t_stack_a	stack_a;
	t_stack_b	stack_b;
	stack_b.top = NULL;
	t_list	*head = NULL;
	t_list	*current;
	t_list	*new = ft_lstnew(2);
	t_list	*new2 = ft_lstnew(3);
	t_list	*new3 = ft_lstnew(10);
	t_list	*new4 = ft_lstnew(4);
	t_list	*new5 = ft_lstnew(5);
	t_list	*new6 = ft_lstnew(9);
	t_list	*new7 = ft_lstnew(15);
	t_list	*new8 = ft_lstnew(22);
	t_list	*new9 = ft_lstnew(109);
	t_list	*new10 = ft_lstnew(8);
	
	ft_lstadd_front(&head, new10);
	ft_lstadd_front(&head, new9);
	ft_lstadd_front(&head, new8);
	ft_lstadd_front(&head, new7);
	ft_lstadd_front(&head, new6);
	ft_lstadd_front(&head, new5);
	ft_lstadd_front(&head, new4);
	ft_lstadd_front(&head, new3);
	ft_lstadd_front(&head, new2);
	ft_lstadd_front(&head, new);
	stack_a.top = head;
    
	current = stack_a.top;
	int	c = 0;
	while (current)
	{
		printf("%d: %i\n", c, current->content);
		current = current->next;
		c++;
	}
	// bubble_sort(&stack_a);
	range_sort_algo(&stack_a, &stack_b);
    
	current = stack_a.top;
	c = 0;
	while (current)
	{
		printf("%d: %i\n", c, current->content);
		current = current->next;
		c++;
	}
}
*/

/*
while ((unsigned int)i < ft_lstsize(stack_a.top))
{
		printf("%d: %d\n", i, arr[i]);
		i++;
	}
	printf("Block Size: %d\n", block_size(&stack_a));
	
	current = head;
	int	c = 0;
	current = stack_a.top;
	while (current)
	{
		printf("%d: %i\n", c, current->content);
		current = current->next;
		c++;
	}

	while ((unsigned int)i < ft_lstsize(head))
	{
		printf("Current: %d\nIndex: %d\n", stack_a->top->content, stack_a->top->index);
		i++;
		stack_a->top = stack_a->top->next;
	}	
*/
