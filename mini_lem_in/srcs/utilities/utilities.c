/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:43:57 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/11 15:03:25 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (true);
		++i;
	}
	return (false);
}

bool	are_same_str(const char *str1, const char *str2)
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

char	*ft_strcpy(char *dest, const char *src)
{
	size_t i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *str)
{
	const size_t	len = ft_strlen(str);
	size_t	i;
	char	*cp_str;

	cp_str = (char *)malloc((len + 1) *sizeof(char));
	if (cp_str != NULL)
	{
		i = 0;
		while (i < len)
		{
			cp_str[i] = str[i];
			++i;
		}
		cp_str[len] = '\0';
	}
	return (cp_str);
}