/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:20:45 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/02 00:19:38 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	display_graph(t_graph *graph)
{
	t_room	*curr_room;
	t_list	*list;

	list = graph->rooms;
	printf("START : %s\n", graph->start->name);
	printf("END : %s\n", graph->end->name);
	while (list != NULL)
	{
		curr_room = list->data;
		if (curr_room != NULL)
			display_room(curr_room);
		list = list->next;
	}
	destroy_room(curr_room);
	if (graph->shortest_paths->data != NULL)
	{
		printf("Shortest path(s) :\n");
		display_path_list(graph->shortest_paths);
	}
	else
		printf("There isn't existing path between %s and %s.\n",
										graph->start->name, graph->end->name);
}
