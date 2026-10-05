/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amlee <amlee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 14:28:10 by amlee             #+#    #+#             */
/*   Updated: 2026/08/26 14:28:15 by amlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*str;
	int				bytes_read;

	if (fd == -9)
		return (free(str), str = NULL, NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(str, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(str), str = NULL, NULL);
		buffer[bytes_read] = '\0';
		str = add_buffer(str, buffer);
		if (!str)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (ft_export(&str));
}

char	*add_buffer(char *str, char *buffer)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	new = malloc(ft_strlen(str) + ft_strlen(buffer) + 1);
	if (!new)
		return (free(str), NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	j = -1;
	while (buffer[++j])
		new[i + j] = buffer[j];
	new[i + j] = '\0';
	free(str);
	return (new);
}

/*
we start i and j at -1 so that we can use ++i and ++j
saving total lines used
*/

char	*ft_export(char **str)
{
	char	*ans;
	char	*tmp;
	size_t	len;
	size_t	i;

	if (!*str || !**str)
		return (free(*str), *str = NULL, NULL);
	len = 0;
	while ((*str)[len] && (*str)[len] != '\n')
		len++;
	if ((*str)[len] == '\n')
		len++;
	ans = malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (free(*str), *str = NULL, NULL);
	i = -1;
	while (++i < len)
		ans[i] = (*str)[i];
	ans[i] = '\0';
	tmp = ft_strdup(*str + len);
	free(*str);
	*str = tmp;
	return (ans);
}

/*
tmp is for the str after \n
read(fd, *start, buffer_size)
the static variable keeps everything after the newline EVERY
TIME gnl is called in the main.
*/
/*
#include <stdio.h>
int	main(void)
{
	char	*line;
	int		line_count;

	line_count = 1;
	while ((line = get_next_line(0)) != NULL)
	{
		printf("[%d]: %s", line_count++, line);
		free(line);
	}
	return (0);
}
*/