/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:42:33 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 15:07:22 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

static bool	is_valid_arg(const char *arg, const char *pattern)
{
	return (is_alnum(arg) == true
		&& ft_strlen(arg) > 0
		&& ft_strchr(arg, *pattern) == NULL);
}

bool	is_perfect_arg(const char *arg)
{
	return (is_valid_arg(arg, START_PATTERN)
		&& is_valid_arg(arg, END_PATTERN) && is_valid_arg(arg, DELIM));
}

const char	*is_start_inst(const char *line)
{
	const size_t	size = ft_strlen(START_PATTERN);
	const char		*arg;

	if (ft_is_equaln(line, START_PATTERN, size))
	{
		arg = line + ft_strlen(START_PATTERN);
		if (is_perfect_arg(arg) == true)
			return (arg);
	}
	return (NULL);
}

const char	*is_end_inst(const char *line)
{
	const size_t	size = ft_strlen(END_PATTERN);
	const char		*arg;

	if (ft_is_equaln(line, END_PATTERN, size))
	{
		arg = line + ft_strlen(END_PATTERN);
		if (is_perfect_arg(arg) == true)
			return (arg);
	}
	return (NULL);
}

const char	*is_link_inst(const char *line)
{
	char		*cpy;
	const char	*arg;

	cpy = ft_strdup(line);
	arg = ft_strchr(cpy, *DELIM);
	free(cpy);
	if (arg != NULL)
		return (line);
	return (NULL);
}
