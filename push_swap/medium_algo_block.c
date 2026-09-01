/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo_block.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:37:40 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/01 16:03:36 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	block_size(t_stack_a *stack_a);
static int	ft_sqrt(int nb);

void	block_sort(t_stack_a *stack_a)
{
	
}

static int	block_size(t_stack_a *stack_a)
{
	int	n;
	int	k;

	n = ft_lstsize(stack_a->top);
	k = ft_sqrt(n);
	return (k);
}
// k ≈ √n (Check notes) with custom sqrt function.

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
} // update sqrt to return math ceiling