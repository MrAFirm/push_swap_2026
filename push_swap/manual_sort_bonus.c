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

static int	logic_1(char *line, t_stack_a *a, t_stack_b *b, t_bench *bench);
static int	logic_2(char *line, t_stack_b *b, t_bench *bench);
static int	logic_3(char *line, t_stack_a *a, t_stack_b *b, t_bench *bench);
static int	logic_4(char *line, t_stack_a *a, t_stack_b *b, t_bench *bench);

int	manual_sort(t_stack_a *a, t_stack_b *b, t_bench *bench)
{
	char		*line;

	b->top = NULL;
	b->value->flag = 0;
	line = get_next_line(0);
	if (line)
	{
		while (line)
		{
			if (!logic_1(line, a, b, bench) && !logic_2(line, b, bench)
				&& !logic_3(line, a, b, bench)
				&& !logic_4(line, a, b, bench))
			{
				write(2, "Error\n", 6);
				break ;
			}
			free(line);
			line = get_next_line(0);
		}
		check(a, b);
	}
	free(bench);
	free(line);
	return (1);
}

static int	logic_1(char *line, t_stack_a *a, t_stack_b *b, t_bench *bench)
{
	if (ft_strncmp(line, "sa", 2) == 0)
	{
		swap_a(a, bench);
		return (1);
	}
	else if (ft_strncmp(line, "ra", 2) == 0)
	{
		rotate_a(a, bench);
		return (1);
	}
	else if (ft_strncmp(line, "rra", 3) == 0)
	{
		rrotate_a(a, bench);
		return (1);
	}
	else if (ft_strncmp(line, "pb", 2) == 0)
	{
		push_b(a, b, bench);
		return (1);
	}
	return (0);
}

static int	logic_2(char *line, t_stack_b *b, t_bench *bench)
{
	if (ft_strncmp(line, "sb", 2) == 0)
	{
		if (b->top && b->top->next)
		{
			swap_b(b, bench);
			return (1);
		}
	}
	else if (ft_strncmp(line, "rb", 2) == 0)
	{
		if (b->top && b->top->next)
		{
			rotate_b(b, bench);
			return (1);
		}
	}
	return (0);
}

static int	logic_3(char *line, t_stack_a *a, t_stack_b *b, t_bench *bench)
{
	if (ft_strncmp(line, "ss", 2) == 0)
	{
		if (a->top && b->top)
		{
			swap_s(a, b, bench);
			return (1);
		}
	}
	else if (ft_strncmp(line, "rrr", 3) == 0)
	{
		if (a->top && b->top)
		{
			rrotate_r(a, b, bench);
			return (1);
		}
	}
	else if (ft_strncmp(line, "rrb", 3) == 0)
	{
		if (b->top && b->top->next)
		{
			rrotate_b(b, bench);
			return (1);
		}
	}
	return (0);
}

static int	logic_4(char *line, t_stack_a *a, t_stack_b *b, t_bench *bench)
{
	if (ft_strncmp(line, "rr", 2) == 0)
	{
		if (a->top && b->top)
		{
			rotate_r(a, b, bench);
			return (1);
		}
	}
	else if (ft_strncmp(line, "pa", 2) == 0)
	{
		if (b->top)
		{
			push_a(a, b, bench);
			return (1);
		}
	}
	return (0);
}
