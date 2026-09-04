/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo_block_prototype.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:37:40 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/04 22:15:22 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		block_size(t_stack_a *stack_a);
static int		ft_sqrt(int nb);
static t_list	*in_block_swaps(t_list *block);
static t_list	*min_heap_merge(t_list **block, int blocksize);
// static t_list	*merge_list(t_stack_b *stack_b, t_list *final_stack);

void	block_sort(t_stack_a *stack_a)
{
	int		blocksize;
	int		j;
	int		i;
	t_list	**block;
	t_list	*head;
	t_list	*new;
	t_list	*final;
	t_list	*current;

	blocksize = block_size(stack_a);
	head = stack_a->top;
	block = ft_calloc(blocksize, sizeof(t_list *));
	if (!block || blocksize == 0)
		return ;
	j = 0;
	while (j < blocksize)
	{
		head = stack_a->top;
		i = 0;
		while (i < blocksize && stack_a->top != NULL)
		{
			new = ft_lstnew(stack_a->top->content);
			ft_lstadd_back(&block[j], new);
			stack_a->top = stack_a->top->next;
			i++;
		}
		block[j] = in_block_swaps(block[j]);
		// printf("block[%d]: %d\n", j, block[j]->content);
		// printf("block[%d]: %d\n", j, block[j]->next->content);
		j++;
	}
	final = min_heap_merge(block, blocksize);
	current = final;
	// printf("final: %i\n", current->content);
	while (current)
	{
		printf("%i\n", current->content);
		current = current->next;
	}
	stack_a->top = head;
}

static t_list	*in_block_swaps(t_list *block)
{
	size_t	i;
	size_t	k;
	t_list	*list;
	t_list	*head;
	int		temp;

	i = 0;
	head = block;
	while (i < ft_lstsize(block))
	{
		list = block;
		k = 0;
		while (k < ft_lstsize(block) - i - 1)
		{
			if (list->content > list->next->content)
			{
				temp = list->content;
				list->content = list->next->content;
				list->next->content = temp;
			}
			list = list->next;
			k++;
		}
		i++;
	}
	return (block);
}

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
static t_list	*min_heap_merge(t_list **block, int blocksize)
{
	int			j;
	int			smallest;
	int			winner;
	t_list		*head;
	t_list		*next_head;
	t_list		*new_list;
	int			num_remain;

	j = 0;
	head = *block;
	num_remain = 0;
	new_list = NULL;
	while (j < blocksize)
	{
		num_remain += (int)ft_lstsize(block[j]);
		j++;
	}
	winner = -1; // if no winner found yet.
	while (num_remain > 0)
	{
		// printf("remain: %d\n", num_remain);
		head = *block;
		j = 0;
		smallest = 2147483647;
		while (j < blocksize)
		{
			if (block[j] != NULL && block[j]->content < smallest)
			{
				smallest = block[j]->content;
				winner = j;
			}
			j++;
		}
		if (winner != -1)
		{
			next_head = block[winner]->next;
			block[winner]->next = NULL;
			ft_lstadd_back(&new_list, block[winner]);
			block[winner] = next_head;
		}
		// printf("winner: %i\n", winner);
		// printf("smallest: %i\n", smallest);
		// // printf("block[winner]: %i\n", block[winner]->content);
		num_remain--;
	}
	return (new_list);
}

// static t_list	*merge_list(t_stack_b *stack_b, t_list *final_stack)
// {
	
// }