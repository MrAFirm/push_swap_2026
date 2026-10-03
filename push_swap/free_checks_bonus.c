/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_checks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 02:06:28 by lkhye-ya          #+#    #+#             */
/*   Updated: 2026/10/04 02:07:33 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_check_1(t_flag *a_value)
{
	if (!a_value)
		return (-1);
	return (0);
}

int	free_check_2(t_flag *a_value, t_flag *b_value)
{
	if (!b_value)
	{
		free(a_value);
		return (-1);
	}
	return (0);
}

int	free_check_3(t_flag *a_value, t_flag *b_value, t_bench *bench)
{
	if (!bench)
	{
		free(a_value);
		free(b_value);
		return (-1);
	}
	return (0);
}
