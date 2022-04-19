/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:42:33 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/19 11:12:24 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

static bool	are_same_begin(const char *str, char *pattern)
{
	const char	*str_after_pat = ft_strstr(str, pattern);

	if (str_after_pat == NULL)
		return (false);
	return (ft_strcmp(ft_strstr(str, pattern), str));
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
