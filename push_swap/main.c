/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:11:07 by amlee             #+#    #+#             */
/*   Updated: 2026/09/23 17:03:52 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(int content)
{
	(void)content;
}
/*
static void	lst_create(int ac, char **av, t_list **a)
{
	int		i;
	t_list	*tmp;

	i = 1;
	while (i < ac)
	{
		tmp = ft_lstnew(ft_atoi(av[i]));
		if (!tmp)
		{
			ft_lstclear(a, del);
			return ;
		}
		ft_lstadd_back(a, tmp);
		i++; 
	}
}
*/

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac <= 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!parsing_create(ac, av, &a) || !a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	algo_select(av, a);
	return (0);
}
