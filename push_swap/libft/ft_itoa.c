/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:47:57 by amlee             #+#    #+#             */
/*   Updated: 2026/09/14 21:27:48 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*ans;

	nbr = n;
	len = ft_nbrlen(nbr);
	ans = malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	ans[len] = '\0';
	if (nbr == 0)
		ans[0] = '0';
	if (nbr < 0)
	{
		ans[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		ans[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (ans);
}
/*
#include <stdio.h>
int	main(void)
{
	int		nbr = -2147483648;
	char	*ans = ft_itoa(nbr);

	if (ans)
	{
		printf("%s\n", ans);
		free(ans);
	}
	return (0);
}
*/
