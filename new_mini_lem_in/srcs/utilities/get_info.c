/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:57:37 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/18 18:45:32 by romannbroque     ###   ########.fr       */
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

bool	ft_strcmp(const char *str1, const char *str2)
{
	const size_t	size1 = ft_strlen(str1);
	const size_t	size2 = ft_strlen(str2);
	size_t			i;

	i = 0;
	if (size1 != size2)
		return (false);
	while (i < size1)
	{
		if (str1[i] != str2[i])
			return (false);
		++i;
	}
	return (true);
}
