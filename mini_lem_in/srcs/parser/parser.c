/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:13:29 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/16 18:16:54 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

bool	is_nb(char *str, char end_char)
{
	size_t	i;

	i = 0;
	if (str[i] == '\0' || str[i] == end_char)
		return (false);
	while (str[i] != '\0' && str[i] != end_char)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		++i;
	}
	return (true);
}

bool	are_same_begin(const char *str, const char *pattern)
{
	const size_t	len_str = str_len(str);
	const size_t	len_pat = str_len(pattern);
	size_t			i;

	if (len_str >= len_pat)
	{
		i = 0;
		while (i < len_pat)
		{
			if (str[i] != pattern[i])
				return (false);
			++i;
		}
		return (true);
	}
	return (false);
}

bool	is_start_inst(char *line)
{
	return (are_same_begin(line, START_PATTERN)
			&& is_nb(line + str_len(START_PATTERN), '\0'));
}

bool	is_end_inst(char *line)
{
	return (are_same_begin(line, END_PATTERN)
			&& is_nb(line + str_len(END_PATTERN), '\0'));
}

bool	is_link_inst(char *line)
{
	size_t	i;

	i = 0;
	if (is_nb(line, DELIM) == true)
	{
		while (line[i] != DELIM)
			++i;
		return (is_nb(line + i + 1, '\0'));
	}
	return (false);
}
