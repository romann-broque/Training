/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:55:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 21:43:45 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

result	start(t_graph *graph, const char *command)
{
	t_room	*new;
	char	*arg;

	if (graph->start != NULL)
		return (EXIT_FAILURE);
	arg = ft_strdup(command + ft_strlen(START_PATTERN));
	new = create_room(arg, NULL);
	graph->start = new;
	free(arg);
	return (EXIT_SUCCESS);
}

result	end(t_graph *graph, const char *command)
{
	t_room	*new;
	char	*arg;

	if (graph->end != NULL)
		return (EXIT_FAILURE);
	arg = ft_strdup(command + ft_strlen(END_PATTERN));
	new = create_room(arg, NULL);
	free(arg);
	graph->end = new;
	return (EXIT_SUCCESS);
}

result	ft_link(t_graph *graph, const char *command)
{
	char	*arg1;
	char	*arg2;
	t_room	*room1;
	t_room	*room2;

	arg1  = ft_strtok(command, DELIM);
	arg2 = ft_strdup(command + ft_strlen(arg1) + ft_strlen(DELIM));
	room1 = find_room(graph->rooms, arg1);
	if (room1 == NULL)
		create_n_add_room(&graph->rooms, &room1, arg1);
	room2 = find_room(graph->rooms, arg2);
	if (room2 == NULL)
		create_n_add_room(&graph->rooms, &room2, arg2);
	add_element(&room1->neighboor, room2);
	free(arg1);
	free(arg2);
	return (EXIT_SUCCESS);
}
