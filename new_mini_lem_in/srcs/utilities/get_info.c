/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:57:37 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/20 15:39:13 by romannbroque     ###   ########.fr       */
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
	size_t	size1;
	size_t	size2;
	size_t	i;

	i = 0;
	size1 = ft_strlen(str1);
	size2 = ft_strlen(str2);
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

int	ft_memcmp(const void *ptr1, const void *ptr2, const size_t size)
{
 	unsigned long	delta;
	size_t			i;

	i = 0;
	while (i < size)
	{
		delta = *(unsigned char *)(ptr1 + i) - *(unsigned char *)(ptr2 + i);
		if (delta != 0)
			return (delta);
		++i;
	}
	return (0);
}
