/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:13:29 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/31 22:49:50 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

bool	are_same_begin(char *str, char *pattern)
{
	const size_t	len_str = ft_strlen(str);
	const size_t	len_pat = ft_strlen(pattern);
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
	return (are_same_begin(line, START_PATTERN));
}

bool	is_end_inst(char *line)
{
	return (are_same_begin(line, END_PATTERN));
}

bool	is_link_inst(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != *DELIM)
		++i;
	return (ft_strchr(line + i, *DELIM));
}
