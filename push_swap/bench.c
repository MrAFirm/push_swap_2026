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
	ft_putstr_fd("sb:  ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd("ss:  ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd("pa:  ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd("pb:  ", 2);
	ft_putnbr_fd(bench->pb, 2);
	write(1, "\n", 2);
}

static void	rules_print_two(t_bench *bench)
{
	ft_putstr_fd("[bench] ra:  ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd("rb:  ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd("rr:  ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd("rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd("rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd("rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	write(1, "\n", 2);
}

void	print_bench(t_bench *bench)
{
	if (!bench->enabled)
		return ;
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putstr_fd(bench->disorder, 2);
	
	ft_putstr_fd("[bench] strategy:   ", 2);
	if (bench->strategy == 1)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (bench->strategy == 2)
		ft_putstr_fd("Medium / O(n log n)\n", 2);
	else if (bench->strategy == 3)
		ft_putstr_fd("Complex / O(n)\n", 2);
	else
		ft_putstr_fd("Adaptive / O(n\\sqrt{n})\n", 2);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	write(1, "\n", 2);
	rules_print_one(bench);
	rules_print_two(bench);
}
