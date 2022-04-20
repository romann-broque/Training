/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:42:33 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/20 15:37:49 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

static bool	are_same_begin(const char *str, const char *pattern)
{
	const size_t	size_str = ft_strlen(str);
	const size_t	size_pat = ft_strlen(pattern);

	if (size_str < size_pat)
		return (false);
	return (ft_memcmp((const char *)str, (const char *)pattern, size_pat * sizeof(char)) == 0);
}

bool	is_start_inst(const char *line)
{
	return (are_same_begin(line, START_PATTERN));
}

bool	is_end_inst(const char *line)
{
	return (are_same_begin(line, END_PATTERN));
}

bool	is_link_inst(const char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != *DELIM)
		++i;
	return (line[i] == *DELIM);
}
