/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:55:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/24 23:59:03 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	start(const char *command)
{
	char	*name;

	name  = ft_strdup(command + ft_strlen(START_PATTERN));
	ft_putstr("START ! ");
	ft_putendl(name);
	free(name);
	return (EXIT_SUCCESS);
}

int	end(const char *command)
{
	char	*name;

	name = ft_strdup(command + ft_strlen(END_PATTERN));
	ft_putstr("END ! ");
	ft_putendl(name);
	free(name);
	return (EXIT_SUCCESS);
}

int	ft_link(const char *command)
{
	char	*arg1;
	char	*arg2;

	arg1 = ft_strtok(command, DELIM);
	arg2 = ft_strdup(arg1 + ft_strlen(DELIM));

	ft_putstr("LINK !\n");
	ft_putstr(arg1);
	ft_putstr(";");
	ft_putendl(arg2);

	free(arg1);
	free(arg2);
	return (EXIT_SUCCESS);
}
