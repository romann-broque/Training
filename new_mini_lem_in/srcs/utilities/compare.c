/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:10:21 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 20:10:37 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int	ft_strncmp(const char *str1, const char *str2, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && *str1 == *str2)
	{
		++str1;
		++str2;
		++i;
	}
	if (i == size)
		return (0);
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	const size_t	size1 = ft_strlen(str1);
	const size_t	size2 = ft_strlen(str2);

	if (size1 == size2)
		return (ft_strncmp(str1, str2, size1));
	return (size1 - size2);
}

bool	ft_is_equal(const char *str1, const char *str2)
{
	return (ft_strcmp(str1, str2) == 0);
}

bool	ft_is_equaln(const char *str1, const char *str2, const size_t size)
{
	return (ft_strncmp(str1, str2, size) == 0);
}
