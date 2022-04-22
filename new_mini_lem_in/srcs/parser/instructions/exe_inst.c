/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:55:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/22 15:56:02 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	start(const char *command)
{
	const char	*name = ft_strdup(command + ft_strlen(START_PATTERN));

	ft_putstr("START ! ");
	ft_putstr(name);
	ft_putstr("\n");
	return (EXIT_SUCCESS);
}

int	end(const char *command)
{
	const char	*name = ft_strdup(command + ft_strlen(END_PATTERN));

	ft_putstr("END ! ");
	ft_putstr(name);
	ft_putstr("\n");
	return (EXIT_SUCCESS);
}

int	ft_link(const char *command)
{
	const char	*arg1 = ft_strtok(command, DELIM);
	const char	*arg2 = ft_strchr(ft_strdup(command), *DELIM);

	ft_putstr("LINK !\n");
	ft_putstr(arg1);
	ft_putstr(";");
	ft_putendl(arg2);
	return (EXIT_SUCCESS);
}
