/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:38:30 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 10:12:15 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	display_path_list(t_list *path_list)
{
	t_list	*path;

	if (path_list != NULL)
	{
		path = path_list->data;
		display_list(&path, display_room);
		display_path_list(path_list->next);
	}
}

void	display_graph(t_graph *graph)
{
	t_list	*room;

	if (graph != NULL)
	{
		if (graph->start != NULL && graph->end != NULL)
		{
			ft_putstr("START : ");
			ft_putendl(((t_room *)(graph->start))->name);
			ft_putstr("END : ");
			ft_putendl(((t_room *)(graph->end))->name);
			if (graph->rooms != NULL)
			{
				ft_putendl("\nROOMS : \n");
				room = graph->rooms;
				while (room != NULL)
				{
					full_display_room(room->data);
					room = room->next;
				}
			}
			if (graph->shortest_paths != NULL)
			{
				ft_putendl("\nSHORTEST_PATHS : \n");
				display_path_list(graph->shortest_paths);
			}
			else
			{
				ft_putstr("\nThere isn't existing path between ");
				ft_putstr(graph->start->name);
				ft_putstr(" and ");
				ft_putendl(graph->end->name);
			}
		}
	}
}
