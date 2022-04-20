/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:55:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/20 15:44:37 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	start(const char *command)
{
	char	*name;

	name = ft_strdup(command + ft_strlen(START_PATTERN));
	if (command != NULL)
	{
		ft_putstr("START ! ");
		ft_putstr(name);
		ft_putstr("\n");
	}
	free(name);
	return (EXIT_SUCCESS);
}

int	end(const char *command)
{
	char	*name;

	name = ft_strdup(command + ft_strlen(END_PATTERN));
	if (command != NULL)
	{
		ft_putstr("END ! ");
		ft_putstr(name);
		ft_putstr("\n");
	}
	free(name);
	return (EXIT_SUCCESS);
}

int	ft_link(const char *command)
{
	if (command != NULL)
		ft_putstr("LINK !\n");
	return (EXIT_SUCCESS);
}
