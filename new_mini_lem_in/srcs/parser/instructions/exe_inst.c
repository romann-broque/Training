/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:55:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 16:58:59 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	start(t_graph *graph, const char *command)
{
	if (graph->start != NULL)
		free(graph->start);
	graph->start = ft_strdup(command + ft_strlen(START_PATTERN));
	return (EXIT_SUCCESS);
}

int	end(t_graph *graph, const char *command)
{
	if (graph->end != NULL)
		free(graph->end);
	graph->end = ft_strdup(command + ft_strlen(END_PATTERN));
	return (EXIT_SUCCESS);
}

int	ft_link(t_graph *graph, const char *command)
{
	char	*arg1;
	char	*arg2;
	t_room	*room1;
	t_room	*room2;

	arg1  = ft_strtok(command, DELIM);
	arg2 = ft_strdup(command + ft_strlen(arg1) + ft_strlen(DELIM));
	room1 = find_room(graph->rooms, arg1);
	if (room1 == NULL)
	{
		room1 = create_room(arg1, NULL);
		add_element(&graph->rooms, room1);
	}
	room2 = find_room(graph->rooms, arg2);
	if (room2 == NULL)
	{
		room2 = create_room(arg2, NULL);
		add_element(&graph->rooms, room2);
	}
	add_element(&room1->neighboor, room2);
	free(arg1);
	free(arg2);
	return (EXIT_SUCCESS);
}
