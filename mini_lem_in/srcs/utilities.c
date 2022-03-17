/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:43:57 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/17 21:58:04 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

size_t	str_len(const char *str)
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
