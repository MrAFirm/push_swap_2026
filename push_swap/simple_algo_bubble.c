/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo_bubble.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:37:37 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/02 21:56:25 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack_a *stack_a)
{
	t_list	*lst;
	size_t	i;
	size_t	j;
	t_list	*head;

	i = 0;
	head = stack_a->top;
	while (i < ft_lstsize(stack_a->top))
	{
		lst = stack_a->top;
		j = 0;
		while (j < ft_lstsize(stack_a->top) - i - 1)
		{
			if (lst->content > lst->next->content)
			{
				swap_a(stack_a);
				lst = stack_a->top->next;
			}
			else
			{
				rotate_a(stack_a);
				lst = stack_a->top;
			}
			j++;
		}
		while (stack_a->top != head)
			rrotate_a(stack_a);
		i++;
	}
}
