/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo_block.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 22:15:32 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/04 23:19:04 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list   *determine_block(t_stack_a *stack_a, int blocksize);
static int      block_size(t_stack_a *stack_a);
static int      ft_sqrt(int nb);

static t_list   *determine_block(t_stack_a *stack_a, int blocksize)
{
    t_list  *block_start;
    t_list  *current;
    int    pos;

    block_start = stack_a->top;
    current = stack_a->top;
    pos = 0;
    blocksize *= 2;
    while (current && pos < blocksize)
    {
        pos++;
        current = current->next;
    }
    return (block_start + pos);
}

static int  get_next_block(t_stack_a *stack_a)
{
    
}

static int  block_size(t_stack_a *stack_a)
{
    int totalsize;
    int blocksize;

    totalsize = ft_lstsize(stack_a->top);
    blocksize = ft_sqrt(totalsize);
    return (blocksize);
}

static int  ft_sqrt(int nb)
{
    int i;

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
	t_list	*head = NULL;
	// t_list	*current;
	t_list	*new = ft_lstnew(3);
	t_list	*new2 = ft_lstnew(2);
	t_list	*new3 = ft_lstnew(1);
	
	ft_lstadd_front(&head, new3);
	ft_lstadd_front(&head, new2);
	ft_lstadd_front(&head, new);
    stack_a.top = head;

    printf("%d\n", block_size(&stack_a));
}