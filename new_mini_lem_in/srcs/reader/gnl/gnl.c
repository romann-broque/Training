/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:59:53 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/15 17:43:09 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <string.h>
#include <stdio.h>
#define LINE_OK 1
#define CONTINUE 0

int	get_rest_until_newline(char **line, char **rest)
{
	char	*newline_ptr;
	int		ret_value;

	newline_ptr = ft_strchr(*rest, '\n');
	if (newline_ptr == NULL)
		ret_value = CONTINUE;
	else
	{
		ret_value = LINE_OK;
		newline_ptr[0] = '\0';
		if (newline_ptr[1] == '\0')
			newline_ptr = NULL;
		else
			newline_ptr = ft_strdup(newline_ptr + 1);
	}
	*line = ft_strdup(*rest);
	free(*rest);
	*rest = newline_ptr;
	return (ret_value);
}

void	read_from_fd_until_newline(char **line, char **rest, const int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*newline_ptr;
	ssize_t	read_ret;

	read_ret = read(fd, buffer, BUFFER_SIZE);
	while (read_ret > 0)
	{
		buffer[read_ret] = '\0';
		newline_ptr = ft_strchr(buffer, '\n');
		if (newline_ptr == NULL)
			*line = ft_stradd(line, buffer);
		else
		{
			newline_ptr[0] = '\0';
			*line = ft_stradd(line, buffer);
			if (newline_ptr[1] != '\0')
				*rest = ft_strdup(newline_ptr + 1);
			break ;
		}
		read_ret = read(fd, buffer, BUFFER_SIZE);
	}
}

char	*get_next_line(const int fd)
{
	static char	*rest = NULL;
	char		*line;

	line = NULL;
	if (rest == NULL || get_rest_until_newline(&line, &rest) == CONTINUE)
		read_from_fd_until_newline(&line, &rest, fd);
	return (line);
}
