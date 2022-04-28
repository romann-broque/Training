/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:55:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/29 00:01:04 by romannbroque     ###   ########.fr       */
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
	new = find_room(graph->rooms, arg);
	if (new == NULL)
		create_n_add_room(&graph->rooms, &new, arg);
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
	new = find_room(graph->rooms, arg);
	if (new == NULL)
		create_n_add_room(&graph->rooms, &new, arg);
	graph->end = new;
	free(arg);
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
	find_or_add(&graph->rooms, &room1, arg1);
	find_or_add(&graph->rooms, &room2, arg2);
	add_element(&room1->neighboor, room2);
	free(arg1);
	free(arg2);
	return (EXIT_SUCCESS);
}
