/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:52:43 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/10 18:30:36 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# include <stdio.h>

typedef struct	stack_a
{
	t_list			*top;
	struct stack_b	*push_num;
}	t_stack_a;

typedef struct	stack_b
{
	t_list			*top;
	struct stack_a	*push_num;
}	t_stack_b;

/* Algorithms */
void	bubble_sort(t_stack_a *stack_a);
void	range_sort_algo(t_stack_a *stack_a, t_stack_b *stack_b);
float	compute_disorder(t_stack_a *stack_a);
void	custom_adapt_algo(char *argv, t_stack_a *stack_a, t_stack_b *stack_b);

/* Operations */
void	swap_a(t_stack_a *stack_a);
void	swap_b(t_stack_b *stack_b);
void	rotate_a(t_stack_a *stack_a);
void	rotate_b(t_stack_b *stack_b);
void	rrotate_a(t_stack_a *stack_a);
void	push_a(t_stack_a *stack_a, t_stack_b *stack_b);
void	push_b(t_stack_a *stack_a, t_stack_b *stack_b);

#endif