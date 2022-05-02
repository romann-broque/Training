/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:11:19 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 10:20:48 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	path_finder(t_graph *graph, t_room *room, t_list **path)
{
	const t_list	*neighboors = room->neighboor;
	t_room			*curr_room;

	room->lock = true;
	if (room == graph->end)
		extract_path(graph, path);
	else
	{
		while (neighboors != NULL)
		{
			curr_room = (t_room *)neighboors->data;
			if (curr_room->lock == false)
			{
				add_element(path, curr_room);
				path_finder(graph, curr_room, path);
				cut(path, NULL);
			}
			neighboors = neighboors->next;
		}
	}
	room->lock = false;
}

void	get_shortest_paths(t_graph *graph)
{
	t_list	**first_path;

	first_path = (t_list **)malloc(sizeof(t_list *));
	if (first_path != NULL)
	{
		*first_path = create_list(graph->start, NULL);
		path_finder(graph, graph->start, first_path);
	}
	destroy_list(first_path, NULL);
	free(first_path);
}
