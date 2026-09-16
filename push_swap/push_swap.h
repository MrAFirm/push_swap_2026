/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:52:43 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/16 21:46:50 by likhye-y         ###   ########.fr       */
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

/* Blocksize Calc Formula k ≈ √n */
int	block_size(t_stack_a *stack_a);
int	ft_sqrt(int nb);

/* Operations */
void	swap_a(t_stack_a *stack_a);
void	swap_b(t_stack_b *stack_b);
void	rotate_a(t_stack_a *stack_a);
void	rotate_b(t_stack_b *stack_b);
void	push_a(t_stack_a *stack_a, t_stack_b *stack_b);
void	push_b(t_stack_a *stack_a, t_stack_b *stack_b);

/* Simple Algo n² */
void	bubble_sort(t_stack_a *stack_a);

/* Medium Algo n√n */
void	range_sort_algo(t_stack_a *stack_a, t_stack_b *stack_b);
float	compute_disorder(t_stack_a *stack_a);
void	custom_adapt_algo(t_stack_a *stack_a, t_stack_b *stack_b);

/* Medium Algo Utils */
void	push_range(t_stack_a *a, t_stack_b *b, int range_start, int range_end);
int		*next_range_start(int range_start, int range_end, int blocksize);
int		size_stack_a(t_stack_a *stack_a, int size);
void	check_smallest(t_stack_a *stack_a, t_list *head, int manual_i, int *winner);
void	coords_compress(t_stack_a *stack_a);

/* Parsing Util */
void	algo_select(char **av, t_list *a);

/* Amanda's parts */
/* Complex Algo n log n */
void	index_stack(t_list *a);
void	radix(t_list **a, t_list **b);

/* Complex Algo Operations */
void	ra(t_list **a);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);

/* Parsing Utils */
void	del(int content);
int		check_mode(char **av);
int		parsing_create(int ac, char **av, t_list **a);
void	print_bench(t_bench *bench);

/* END */

/* Extra Operations NOT in use */
void	rrotate_a(t_stack_a *stack_a);
void	rrotate_b(t_stack_b *stack_b);
void	swap_s(t_stack_a *stack_a, t_stack_b *stack_b);
void	rotate_r(t_stack_a *stack_a, t_stack_b *stack_b);
void	rrotate_r(t_stack_a *stack_a, t_stack_b *stack_b);

#endif