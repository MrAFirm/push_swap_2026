/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:52:12 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/16 15:52:12 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rules_print_one(t_bench *bench)
{
	ft_putstr_fd("[bench] sa:  ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd(" sb:  ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd(" ss:  ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd(" pa:  ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd(" pb:  ", 2);
	ft_putnbr_fd(bench->pb, 2);
	write(2, "\n", 1);
}

static void	rules_print_two(t_bench *bench)
{
	ft_putstr_fd("[bench] ra:  ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd(" rb:  ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd(" rr:  ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	write(2, "\n", 1);
}

char	*dis_ftoa(t_stack_a *stack_a)
{
	float	disorder;
	int		mult;

	disorder = 0.0;
	disorder = compute_disorder(stack_a);
	mult = get_mult();
	return (ft_ftoa(disorder, mult));
}

void	init_bench(t_bench *bench, t_stack_a *stack_a)
{
	char	*dis;

	dis = dis_ftoa(stack_a);
	bench->enabled = 0;
	bench->strategy = 0;
	bench->disorder = dis;
	bench->total_ops = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	free(dis);
}

void	print_bench(t_bench *bench)
{
	if (bench->enabled == 0)
		return ;
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putstr_fd(bench->disorder, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy:   ", 2);
	if (bench->strategy == 1)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (bench->strategy == 2)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (bench->strategy == 3)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
		ft_putstr_fd("Adaptive / O(n√n)\n", 2);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	write(2, "\n", 1);
	rules_print_one(bench);
	rules_print_two(bench);
}
