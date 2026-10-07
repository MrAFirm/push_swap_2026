/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:11:07 by amlee             #+#    #+#             */
/*   Updated: 2026/09/30 01:10:52 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(int content)
{
	(void)content;
}

int	main(int ac, char **av)
{
	t_list		*a;

	if (ac <= 1)
		return (0);
	a = NULL;
	if (!parsing_create(ac, av, &a) || !a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	algo_select(av, a);
	return (0);
}
