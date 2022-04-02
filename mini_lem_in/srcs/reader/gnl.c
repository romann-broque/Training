/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:32:18 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/01 11:38:16 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "utilities.h"

char	*concatenate(const char *str1, const char *str2)
{
	char			*new_str;
	size_t			size_s1;
	size_t			size_s2;

	if (str1 == NULL)
		str1 = "";
	if (str2 == NULL)
		str2 = "";
	size_s1 = ft_strlen(str1);
	size_s2 = ft_strlen(str2);
	new_str = (char *)malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (new_str != NULL)
	{

		ft_strcpy(new_str, str1);
		ft_strcpy(new_str + size_s1, str2);
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
			free(rest);
			rest = keep_end(buffer, i);
			break;
		}
		++i;
	}
	return (rest);
}

void ft_bzero(void *ptr, size_t size)
{
	size_t i;
	
	i = 0;
	while (i < size)
	{
		((uint8_t *)ptr)[i] = 0;
		++i;
	}
}

char	*get_line(int fd, char **rest)
{
	char	*line;
	char	buffer[BUFFER_SIZE + 1];

	ft_bzero(buffer, BUFFER_SIZE + 1);
	line = *rest;
	if (*rest != NULL && **rest == '\n')
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
	line = keep_beginning(line, ft_strlen(*rest));
	return (line);
}

char	 *get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*next_line;

	next_line = get_line(fd, &rest);	
	return (next_line);
}
