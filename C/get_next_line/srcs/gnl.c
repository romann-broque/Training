/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:32:18 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/16 15:31:02 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*concatenate(char *str1, char *str2)
{
	char			*new_str;
	const size_t	old_size = str_len(str1);
	const size_t	new_size = old_size + str_len(str2);
	size_t			i;
	size_t			j;

	new_str = (char *)malloc((new_size + 1) * sizeof(char));
	if (new_str != NULL)
	{
		i = 0;
		j = 0;
		while (i < new_size)
		{
			if (i < old_size)
				new_str[i] = str1[i];
			else
			{
				new_str[i] = str2[j];
				++j;
			}
			++i;
		}
		new_str[new_size] = '\0';
	}
	return (new_str);
}

char	*get_nxt_buf(int fd, char *buffer)
{
	const size_t	nbof_bytes = read(fd, buffer, BUFFER_SIZE);

	if (nbof_bytes > 0)
		return (buffer);
	return (NULL);
}

char	*get_rest(char *buffer, char *rest)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
		{
			rest = keep_end(buffer, i);
			break;
		}
		++i;
	}
	return (rest);
}

char	*get_line(int fd, char **rest)
{
	char	*line;
	char	*buffer;
	
	buffer = init_buf();
	line = *rest;
	if (*rest != NULL && *rest[0] == '\n')
	{
		*rest = keep_end(*rest, 0);
		return (EMPTY_LINE);
	}
	while (ft_strchr(buffer, '\n') == false)
	{
		get_nxt_buf(fd, buffer);
		if (*buffer == '\0')
			return (NULL);
		line = concatenate(line, buffer);
	}
	*rest = get_rest(buffer, *rest);
	line = keep_beginning(line, str_len(*rest));
	free(buffer);
	return (line);
}

char	 *get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*next_line;

	next_line = get_line(fd, &rest);	
	return (next_line);
}
