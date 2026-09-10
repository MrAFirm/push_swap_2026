/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:38:21 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/10 18:06:41 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack_a *stack_a)
{
	t_list	*head;
	int		size;
	int		mistakes;
	int		total_pairs;
	int		i;
	t_list	*current;
	t_list	*iter_node;
	int		j;

	head = stack_a->top;
	size = (int)ft_lstsize(head);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	current = stack_a->top;
	while (i < size - 1)
	{
		j = i + 1;
		iter_node = current->next;
		while (j < size)
		{
			total_pairs += 1;
			if (current->content > iter_node->content)
				mistakes += 1;
			iter_node = iter_node->next;
			j++;
		}
		current = current->next;
		i++;
	}
	return ((float)mistakes / (float)total_pairs);
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

	printf("%.1f", compute_disorder(&stack_a));
}