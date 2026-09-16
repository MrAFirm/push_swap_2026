/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amlee <amlee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 13:41:56 by amlee             #+#    #+#             */
/*   Updated: 2026/08/31 13:41:58 by amlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_lstcpy(t_list *l, void (d)(int))
{
	t_list	*copy;
	t_list	*tmp;
	int		c;

	copy = NULL;
	if (!l || !d)
		return (NULL);
	while (l)
	{
		c = l->content;
		tmp = ft_lstnew(c);
		if (!tmp)
		{
			d(c);
			ft_lstclear(&copy, d);
			return (NULL);
		}
		ft_lstadd_back(&copy, tmp);
		l = l->next;
	}
	return (copy);
}

void	index_stack(t_list *a)
{
	t_list	*x;
	t_list	*y;
	t_list	*copy;
	int		i;

	copy = ft_lstcpy(a, del);
	if (!copy)
		return ;
	x = a;
	while (x)
    {
		i = 0;
		y = copy;
		while (y)
 		{
			if (y->content < x->content)
				i++;
			y = y->next;
		}
		x->content = i; 
		x = x->next;
	}
	ft_lstclear(&copy, del);
}
//indexes based on how many smaller values there are

void	radix(t_list **a, t_list **b)
{
	int	size;
	int	max;
	int	i;
	int	j;

	i = 0;
	max = 0;
	size = ft_lstsize(*a);
	while (((size - 1) >> max) != 0)
		max++;
	while (i < max)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->content >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b != NULL)
			pa(a, b);
		i++;
	}
}
