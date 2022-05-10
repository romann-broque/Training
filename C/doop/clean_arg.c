/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:29:18 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/25 10:39:31 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static bool	is_whitespace(const char c)
{
	return (c == ' ' || c == '\t');
}

static char	*remove_leading_whitespaces(char *str)
{
	while (is_whitespace(*str) == true)
		++str;
	return (str);
}

static char	*remove_trailing_whitespaces(char *str)
{
	size_t			i;
	const size_t	len = str_len(str);

	i = 0;
	while (i < len && is_whitespace(str[len - i - 1]) == true)
	{
		str[len - i - 1] = '\0';
		i++;
	}
	return (str);
}

char	*trim(char *str)
{
	return (remove_trailing_whitespaces(remove_leading_whitespaces(str)));
}
