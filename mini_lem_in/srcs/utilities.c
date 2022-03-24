/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:43:57 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/23 14:18:58 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

size_t	str_len(const char *str)
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

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (true);
		++i;
	}
	return (false);
}

bool	are_same_str(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (false);
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (false);
		++i;
	}
	return (str1[i] == '\0' && str2[i] == '\0');
}

char *ft_strcpy(char *dest, const char *src)
{
	size_t i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return dest;
}

