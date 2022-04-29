/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:42:33 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/29 11:21:10 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

bool	is_valid_arg(char *arg, const char *pattern)
{
	return (ft_strlen(arg) > 0 && ft_strchr(arg, *pattern) == NULL);
}

char	*is_start_inst(const char *line)
{
	const size_t	size = ft_strlen(START_PATTERN);
	char			*arg;

	if (ft_is_equaln(line, START_PATTERN, size))
	{
		arg = ft_strdup(line + ft_strlen(START_PATTERN));
		if (is_valid_arg(arg, START_PATTERN))
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
		if (is_valid_arg(arg, END_PATTERN))
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
