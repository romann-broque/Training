/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:42:33 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/22 10:48:02 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

bool	is_start_inst(const char *line)
{
	const size_t	size = ft_strlen(START_PATTERN);

	return (ft_is_equaln(line, START_PATTERN, size));
}

bool	is_end_inst(const char *line)
{
	const size_t	size = ft_strlen(END_PATTERN);

	return (ft_is_equaln(line, END_PATTERN, size));
}

bool	is_link_inst(const char *line)
{
	return (ft_strchr(ft_strdup(line), *DELIM) != NULL);
}
