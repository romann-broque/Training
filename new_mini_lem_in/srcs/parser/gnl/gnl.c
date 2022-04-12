/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:59:53 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/12 16:02:08 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <stdio.h>

static void	get_next_buffer(int fd, char *buffer)
{
	read(fd, buffer, BUFFER_SIZE);
}

static char	*get_rest(const char *buffer)
{
	size_t	i;
	char	*rest;

	i = 0;
	while (buffer[i] != '\n')
		++i;
	rest = ft_strdup(buffer + i);
	return (rest);
}

char	*get_next_line(const int fd)
{
	static char	*rest = NULL;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];

	ft_bzero(buffer, BUFFER_SIZE + 1);
	line = rest;
	if (rest != NULL && *rest == '\n')
	{
		++rest;
		return ("\n");
	}
	while (ft_strchr(buffer, '\n') == false)
	{
		get_next_buffer(fd, buffer);
		if (is_empty(buffer, BUFFER_SIZE) == true)
			return (NULL);
		line = ft_strcat(line, buffer);
	}
	rest = get_rest(buffer);
	cut_str(line, '\n');
	return (line);
}
