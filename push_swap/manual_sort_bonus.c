/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 01:26:31 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/30 22:12:37 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	l_1(char *line, t_stack_a *a, t_stack_b *b, t_bench *bench);
static int	l_2(char *line, t_stack_b *b, t_bench *bench);
static int	l_3(char *line, t_stack_a *a, t_stack_b *b, t_bench *bench);
static int	l_4(char *line, t_stack_a *a, t_stack_b *b, t_bench *bench);

int	manual_sort(t_stack_a *a, t_stack_b *b, t_bench *bench)
{
	char	*line;

	b->top = NULL;
	b->value->flag = 0;
	line = get_next_line(0);
	if (!line && compute_disorder(a) == 0)
		free(line);
	while (line)
	{
		if (!l_1(line, a, b, bench) && !l_2(line, b, bench)
			&& !l_3(line, a, b, bench)
			&& !l_4(line, a, b, bench))
		{
			write(2, "Error\n", 6);
			a->value->flag = 2;
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(0);
	}
	check(a, b);
	get_next_line(-9);
	free(bench->disorder);
	return (free(bench), 1);
}

static int	l_1(char *line, t_stack_a *a, t_stack_b *b, t_bench *bench)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
	{
		swap_a(a, bench);
		return (1);
	}
	else if (ft_strncmp(line, "ra\n", 3) == 0)
	{
		rotate_a(a, bench);
		return (1);
	}
	else if (ft_strncmp(line, "rra\n", 4) == 0)
	{
		rrotate_a(a, bench);
		return (1);
	}
	else if (ft_strncmp(line, "pb\n", 3) == 0)
	{
		push_b(a, b, bench);
		return (1);
	}
	return (0);
}

static int	l_2(char *line, t_stack_b *b, t_bench *bench)
{
	if (ft_strncmp(line, "sb\n", 3) == 0)
	{
		swap_b(b, bench);
		return (1);
	}
	else if (ft_strncmp(line, "rb\n", 3) == 0)
	{
		rotate_b(b, bench);
		return (1);
	}
	return (0);
}

static int	l_3(char *line, t_stack_a *a, t_stack_b *b, t_bench *bench)
{
	if (ft_strncmp(line, "ss\n", 3) == 0)
	{
		swap_s(a, b, bench);
		return (1);
	}
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
	{
		rrotate_r(a, b, bench);
		return (1);
	}
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
	{
		rrotate_b(b, bench);
		return (1);
	}
	return (0);
}

static int	l_4(char *line, t_stack_a *a, t_stack_b *b, t_bench *bench)
{
	if (ft_strncmp(line, "rr\n", 3) == 0)
	{
		rotate_r(a, b, bench);
		return (1);
	}
	else if (ft_strncmp(line, "pa\n", 3) == 0)
	{
		push_a(a, b, bench);
		return (1);
	}
	return (0);
}
