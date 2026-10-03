/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:38:21 by likhye-y          #+#    #+#             */
/*   Updated: 2026/09/14 17:49:30 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static float	logic(t_list *head, t_list *c, int mistakes, int total_pairs);

float	compute_disorder(t_stack_a *stack_a)
{
	t_list	*head;
	int		mistakes;
	int		total_pairs;
	t_list	*c;
	float	result;

	head = stack_a->top;
	mistakes = 0;
	total_pairs = 0;
	c = stack_a->top;
	result = logic(head, c, mistakes, total_pairs);
	return (result);
}

static float	logic(t_list *head, t_list *c, int mistakes, int total_pairs)
{
	int		size;
	int		i;
	int		j;
	t_list	*iter_node;

	size = (int)ft_lstsize(head);
	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		iter_node = c->next;
		while (j < size)
		{
			total_pairs += 1;
			if (c->content > iter_node->content)
				mistakes += 1;
			iter_node = iter_node->next;
			j++;
		}
		c = c->next;
		i++;
	}
	return ((float)mistakes / (float)total_pairs);
}

int	get_mult(void)
{
	int	mult;
	int	i;

	i = 2;
	mult = 1;
	while (i-- > 0)
		mult *= 10;
	return (mult);
}

static char	*join_free(char *s1, char *s2)
{
	char	*ans;

	if (!s1 || !s2)
		return (free(s1), free(s2), NULL);
	ans = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ans);
}

char	*ft_ftoa(float f, int mult)
{
	char	*ans;
	char	*dec;
	int		frac;

	frac = (int)((f - (int)f) * mult);
	if (frac < 0)
		frac = -frac;
	dec = ft_itoa(frac);
	if (!dec)
		return (NULL);
	ans = join_free(ft_itoa((int)f), ft_strjoin(".", dec));
	free(dec);
	return (ans);
}
