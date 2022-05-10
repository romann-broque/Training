/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:38:30 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 14:58:28 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

static void	start_display(t_graph *graph)
{
	if (graph->start != NULL)
	{
		ft_putstr("START: ");
		ft_putendl(((t_room *)(graph->start))->name);
	}
}

static void	end_display(t_graph *graph)
{
	if (graph->end != NULL)
	{
		ft_putstr("END: ");
		ft_putendl(((t_room *)(graph->end))->name);
	}
}

static void	rooms_display(t_graph *graph)
{
	t_list	*room;

	if (graph->rooms != NULL)
	{
		ft_putendl("\nROOMS: \n");
		room = graph->rooms;
		while (room != NULL)
		{
			full_display_room(room->data);
			room = room->next;
		}
	}
}

static void	path_list_display(t_graph *graph)
{
	if (graph->shortest_paths != NULL)
	{
		ft_putstr("\nSHORTEST_PATH");
		if (get_size_list(graph->shortest_paths) > 1)
			ft_putstr("S");
		ft_putstr(":\n\n");
		display_path_list(graph->shortest_paths);
	}
	else
	{
		ft_putstr("\nThere is no path between ");
		ft_putstr(graph->start->name);
		ft_putstr(" and ");
		ft_putstr(graph->end->name);
		ft_putstr(".\n");
	}
}

void	display_graph(t_graph *graph)
{
	if (graph != NULL)
	{
		start_display(graph);
		end_display(graph);
		rooms_display(graph);
		path_list_display(graph);
	}
}
