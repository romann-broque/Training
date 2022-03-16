/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:43:29 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/16 17:43:32 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

bool	ft_strchr(char *str, const char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (true);
		++i;
	}
	return (false);
}

size_t	str_len(char *str)
{
	size_t	len;

	len = 0;
	if (str != NULL)
	{
		while (str[len] != '\0')
			++len;
	}
	return (len);
}

char	*init_buf(void)
{
	char	*buffer;
	size_t	i;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer != NULL)
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			buffer[i] = '\0';
			++i;
		}
	}
	return (buffer);
}

char	*keep_end(char *str, size_t rank)
{
	const size_t	len = str_len(str) - rank;
	size_t			i;
	char			*end_str;

	end_str = (char *)malloc(len * sizeof(char));
	if (end_str != NULL)
	{
		i = 0;
		while (i < len)
		{
			end_str[i] = str[rank + i + 1];
			++i;
		}
	}
	return (end_str);
}

char	*keep_beginning(char *str, size_t rank)
{
	const size_t	len = str_len(str);
	size_t			i;

	i = len - (rank + 1);
	while (i < len)
	{
		str[i] = '\0';
		++i;
	}
	return (str);
}
