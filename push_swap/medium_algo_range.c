/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 22:15:32 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/10 16:07:14 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	de_bubble_sort(t_stack_a *stack_a, t_stack_b *stack_b);
static int	*coords_compress(t_stack_a *stack_a);
static int	block_size(t_stack_a *stack_a);
static int	ft_sqrt(int nb);

void	range_sort_algo(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_list	*head;
	int		size;
	int		i;
	int		range_start;
	int		range_end;
	int		iter;
	int		blocksize;
	int		*arr;

	head = stack_a->top;
	size = (int)ft_lstsize(head);
	i = 0;
	blocksize = block_size(stack_a);
	arr = coords_compress(stack_a);
	range_start = size - blocksize;
	iter = range_start;
	range_end = size - 1;

	while (range_start >= 0)
	{
		while (iter <= range_end)
		{
			if (range_end == 0 && range_start == 0 && stack_a->top->index == 0 && !stack_a->top->next)
			{
				push_b(stack_a, stack_b);
				iter++;
			}
			else
			{
				if (stack_a->top->index >= range_start && stack_a->top->index <= range_end)
				{
					push_b(stack_a, stack_b);
					iter++;
				}
				else
					rotate_a(stack_a);
			}
		}
		if (stack_b->top)
			de_bubble_sort(stack_a, stack_b);
		if (range_start == 0)
			return ;
		if (range_start == 0 && range_end == 0)
			return ;
		range_start -= blocksize;
		if (range_start < 0)
			range_start = 0;
		iter = range_start;
		range_end -= blocksize;
		if (range_end < 0)
			range_end = 0;
	}
}


static void	de_bubble_sort(t_stack_a *stack_a, t_stack_b *stack_b)
{
	size_t	i;
	size_t	j;
	t_list	*head;

	i = 0;
	head = stack_b->top;

	while (i < ft_lstsize(head))
	{
		j = 0;
		while (j < ft_lstsize(head) - i - 1)
		{
			if (stack_b->top->content < stack_b->top->next->content)
				swap_b(stack_b);
			rotate_b(stack_b);
			j++;
		}
		while (j < ft_lstsize(stack_b->top))
		{
			rotate_b(stack_b);
			j++;
		}
		i++;
	}
	while (stack_b->top)
		push_a(stack_a, stack_b);
}

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

//O(n^2)

static int	block_size(t_stack_a *stack_a)
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

static int	ft_sqrt(int nb)
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

int main()
{
	t_stack_a	stack_a;
	t_stack_b	stack_b;
	stack_b.top = NULL;
	t_list	*head = NULL;
	t_list	*current;
	t_list	*new = ft_lstnew(2);
	t_list	*new2 = ft_lstnew(3);
	t_list	*new3 = ft_lstnew(1);
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

	// while ((unsigned int)i < ft_lstsize(stack_a.top))
	// {
	// 	printf("%d: %d\n", i, arr[i]);
	// 	i++;
	// }
	// printf("Block Size: %d\n", block_size(&stack_a));
	
	// current = head;
	// int	c = 0;
	// current = stack_a.top;
	// while (current)
	// {
	// 	printf("%d: %i\n", c, current->content);
	// 	current = current->next;
	// 	c++;
	// }

	// while ((unsigned int)i < ft_lstsize(head))
	// {
	// 	printf("Current: %d\nIndex: %d\n", stack_a->top->content, stack_a->top->index);
	// 	i++;
	// 	stack_a->top = stack_a->top->next;
	// }
	
}
