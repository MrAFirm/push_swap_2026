/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:52:43 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/30 17:20:59 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFFER_SIZE 3

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# include <stdio.h>

typedef struct s_flag
{
	int	flag;
}	t_flag;

typedef struct stack_a
{
	t_list			*top;
	t_flag			*value;
}	t_stack_a;

typedef struct stack_b
{
	t_list			*top;
	t_flag			*value;
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
int		block_size(t_stack_a *stack_a);
int		ft_sqrt(int nb);

/* Operations */
void	swap_a(t_stack_a *stack_a, t_bench *bench);
void	swap_b(t_stack_b *stack_b, t_bench *bench);
void	rotate_a(t_stack_a *stack_a, t_bench *bench);
void	rotate_b(t_stack_b *stack_b, t_bench *bench);
void	push_a(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench);
void	push_b(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench);

/* Medium Algo Utils */
int		size_stack_a(t_stack_a *stack_a, int size);
void	coords_compress(t_stack_a *stack_a);

/* Sort 3 & 5 Numbers */
void	sort_3(t_stack_a *stack_a, t_bench *bench);
void	sort_5(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench);

/* Simple and Medium Util */
int		find_max(t_stack_b *stack_b);
void	drain_b_to_a(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench);

/* Simple Algo n² */
void	bubble_sort(t_stack_a *stack_a, t_bench *bench);

/* Medium Algo n√n */
void	range_sort_algo(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench);
float	compute_disorder(t_stack_a *stack_a);
void	custom_adapt_algo(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *be);

/* Parsing Util */
void	algo_select(char **av, t_list *a);
void	algo_help(char **av, t_stack_a stack_a, t_bench *bench);
void	algo_mid(t_stack_a stack_a, char **av);

/* Checker Bonus */
int		free_check_1(t_flag *a_value);
int		free_check_2(t_flag *a_value, t_flag *b_value);
int		free_check_3(t_flag *a_value, t_flag *b_value, t_bench *bench);
int		man_sort_check(t_stack_a *a, t_stack_b *b, char *line, t_bench *bench);
void	check(t_stack_a *stack_a, t_stack_b *stack_b);
int		manual_sort(t_stack_a *a, t_stack_b *b, t_bench *bench);
void	clear_stat_buf();
char	*add_buffer(char *str, char *buffer);
char	*ft_export(char **str);
char	*get_next_line(int fd);

/* Amanda's parts */
/* Complex Algo n log n */
void	index_stack(t_list *a);
void	radix(t_list **a, t_list **b, t_bench *bench);

/* Complex Algo Operations */
void	ra(t_list **a, t_bench *bench);
void	pb(t_list **a, t_list **b, t_bench *bench);
void	pa(t_list **a, t_list **b, t_bench *bench);

/* Parsing Utils */
void	del(int content);
int		parsing_create(int ac, char **av, t_list **a);
void	print_bench(t_bench *bench);
void	init_bench(t_bench *bench, t_stack_a *stack_a);
char	*ft_ftoa(float f);
int		get_mult(void);

/* END */
/* Extra Operations NOT in use */
void	rrotate_a(t_stack_a *stack_a, t_bench *bench);
void	rrotate_b(t_stack_b *stack_b, t_bench *bench);
void	swap_s(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench);
void	rotate_r(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench);
void	rrotate_r(t_stack_a *stack_a, t_stack_b *stack_b, t_bench *bench);

#endif
