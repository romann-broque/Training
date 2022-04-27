/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:55:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/27 14:29:13 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	start(t_graph **graph, const char *command)
{
	if (*graph == NULL)
		*graph = init_graph();
	if ((*graph)->start != NULL)
		free((*graph)->start);
	(*graph)->start = ft_strdup(command);
	return (EXIT_SUCCESS);
}

int	end(t_graph **graph, const char *command)
{
	if (*graph == NULL)
		*graph = init_graph();
	if ((*graph)->end != NULL)
		free((*graph)->end);
	(*graph)->end = ft_strdup(command);
	return (EXIT_SUCCESS);
}

int	ft_link(t_graph **graph, const char *command)
{
	char	*arg1;
	char	*arg2;

	if (*graph == NULL)
		*graph = init_graph();
	arg1 = ft_strtok(command, DELIM);
	arg2 = ft_strdup(arg1 + ft_strlen(DELIM));

	ft_putstr("LINK !\n");
	ft_putstr(arg1);
	ft_putstr(";");
	ft_putendl(arg2);
	display_list(&(*graph)->rooms);
	free(arg1);
	free(arg2);
	return (EXIT_SUCCESS);
}
