/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:29:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/31 11:20:54 by romannbroque     ###   ########.fr       */
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
				add(*path, curr_room);
				path_finder(graph, curr_room, path);
				cut_path(path);
			}
			neighboors = neighboors->next;
		}
	}
	room->lock = false;
}
