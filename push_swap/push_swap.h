/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:52:43 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/16 16:06:58 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

/*
# include <stdio.h>
*/

typedef struct	stack_a
{
	t_list			*top;
}	t_stack_a;

typedef struct	stack_b
{
	t_list			*top;
}	t_stack_b;

typedef struct s_bench
{
	int		enabled;
	int		strategy;
	char	*disorder;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

/* Blocksize calc */
int	block_size(t_stack_a *stack_a);
int	ft_sqrt(int nb);

/* Operations */
void	swap_a(t_stack_a *stack_a);
void	swap_b(t_stack_b *stack_b);
void	rotate_a(t_stack_a *stack_a);
void	rotate_b(t_stack_b *stack_b);
void	rrotate_a(t_stack_a *stack_a);
void	push_a(t_stack_a *stack_a, t_stack_b *stack_b);
void	push_b(t_stack_a *stack_a, t_stack_b *stack_b);

/* Algorithms */
void	bubble_sort(t_stack_a *stack_a);
void	range_sort_algo(t_stack_a *stack_a, t_stack_b *stack_b);
float	compute_disorder(t_stack_a *stack_a);
void	custom_adapt_algo(char *argv, t_stack_a *stack_a, t_stack_b *stack_b);

/* Algo Utils */
void	push_range(t_stack_a *a, t_stack_b *b, int range_start, int range_end);
int		*next_range_start(int range_start, int range_end, int blocksize);
int		size_stack_a(t_stack_a *stack_a, int size);
void	check_smallest(t_stack_a *stack_a, t_list *head, int manual_i, int *winner);
void	coords_compress(t_stack_a *stack_a);

/* Amanda's part */
void	radix(t_list **a, t_list **b);
void	ra(t_list **a);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	del(int content);
void	index_stack(t_list *a);
int		check_mode(char **av);
void	algo_select(char **av, t_list *a);
int		parsing_create(int ac, char **av, t_list **a);
void	print_bench(t_bench *bench);

#endif