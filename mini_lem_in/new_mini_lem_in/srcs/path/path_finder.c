/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:29:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/28 18:45:09 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	display_shortest_paths(t_graph *graph)
{
	path_finder(graph, graph->shortest_paths, graph->start);
	display_path_list(graph->shortest_paths);
}

void	path_finder(t_graph *graph, t_list *curr_path, t_room *curr_room)
{
	t_list	*neighboors;
	t_room	*neigh;
	t_path	*new;

	new = create_path(graph->start);
	curr_room->lock = true;
	if (curr_room != graph->end)
	{
		neighboors = curr_room->neighboor;
		while (neighboors != NULL)
		{
			neigh = neighboors->data;
			if (neigh->lock == false)
			{
				add_step(curr_path->data, curr_room);
				path_finder(graph, curr_path, neigh);
			}
			neighboors = neighboors->next;
		}
		if (get_last_room(curr_path->data) == graph->end)
			add(curr_path, new);
	}
	else
		add_step(curr_path->data, curr_room);
//		path_finder(graph, curr_path->next, curr_room);
	curr_room->lock = false;
}
