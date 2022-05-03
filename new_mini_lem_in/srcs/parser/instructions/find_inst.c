/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:42:33 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 12:03:56 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

static bool	is_valid_arg(char *arg, const char *pattern)
{
	return (ft_strlen(arg) > 0 && ft_strchr(arg, *pattern) == NULL);
}

bool	is_perfect_arg(char *arg)
{
	return (is_valid_arg(arg, START_PATTERN)
		&& is_valid_arg(arg, END_PATTERN) && is_valid_arg(arg, DELIM));
}

char	*is_start_inst(const char *line)
{
	const size_t	size = ft_strlen(START_PATTERN);
	char			*arg;

	if (ft_is_equaln(line, START_PATTERN, size))
	{
		arg = ft_strdup(line + ft_strlen(START_PATTERN));
		if (is_perfect_arg(arg) == true)
			return (arg);
	}
	return (NULL);
}

char	*is_end_inst(const char *line)
{
	const size_t	size = ft_strlen(END_PATTERN);
	char			*arg;

	if (ft_is_equaln(line, END_PATTERN, size))
	{
		arg = ft_strdup(line + ft_strlen(END_PATTERN));
		if (is_perfect_arg(arg) == true)
			return (arg);
	}
	return (NULL);
}

char	*is_link_inst(const char *line)
{
	char	*cpy;
	char	*arg;

	cpy = ft_strdup(line);
	arg = ft_strchr(cpy, *DELIM);
	free(cpy);
	if (arg != NULL)
		return (ft_strdup(line));
	return (NULL);
}
