/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 21:40:47 by likhye-y          #+#    #+#             */
/*   Updated: 2026/08/28 17:25:43 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack_a *stack_a)
{
	int	temp;

	temp = stack_a->top->content;
	stack_a->top->content = stack_a->top->next->content;
	stack_a->top->next->content = temp;
    write(1, "sa\n", 3);
}
