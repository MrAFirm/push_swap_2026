/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:35:10 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/09 15:35:39 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack_b *stack_b)
{
	int	temp;

	temp = stack_b->top->content;
	stack_b->top->content = stack_b->top->next->content;
	stack_b->top->next->content = temp;
    write(1, "sb\n", 3);
}
