/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:57:37 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/14 09:51:30 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

bool	ft_strchr(const char *str, const char c)
{
	size_t	i;

	if (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] == c)
				return (true);
			++i;
		}
	}
	return (c == '\0');
}

bool	is_empty(const char *str, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (str[i] != 0)
			return (false);
		++i;
	}
	return (true);
}
