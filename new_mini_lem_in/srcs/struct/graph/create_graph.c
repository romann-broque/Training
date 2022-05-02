/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:28:10 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 10:35:22 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	init_graph(t_graph *graph)
{
	if (graph != NULL)
	{
		graph->rooms = NULL;
		graph->shortest_paths = NULL;
		graph->start = NULL;
		graph->end = NULL;
	}
}

t_graph *graph_keeper(t_graph *graph)
{
	static t_graph *glob_graph = NULL;

	if (graph != GET)
		glob_graph = graph;
	return (glob_graph);
}

t_graph *get_graph(void)
{
	return (graph_keeper(GET));
}

void 	set_graph(t_graph *graph)
{
	graph_keeper(graph);
}
