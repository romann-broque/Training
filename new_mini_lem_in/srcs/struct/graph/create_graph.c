/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:28:10 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/27 15:06:18 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_graph	*init_graph(void)
{
	t_graph	*new;

	new = (t_graph *)malloc(sizeof(t_graph));
	if (new != NULL)
	{
		new->rooms = NULL;
		new->start = NULL;
		new->end = NULL;
	}
	return (new);
}

t_graph *graph_keeper(t_graph *graph)
{
	static t_graph *glob_graph = NULL;

	if (graph != GET)
		glob_graph = graph;
	return glob_graph;
}

t_graph *get_graph(void)
{
	return graph_keeper(GET);
}

void set_graph(t_graph *graph)
{
	graph_keeper(graph);
}
