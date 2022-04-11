/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:00:59 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/11 15:09:13 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_graph *init_graph(void)
{
	t_graph	*new;

	new = (t_graph *)malloc(sizeof(t_graph));
	if (new != NULL)
	{
		new->start = NULL;
		new->end = NULL;
		new->rooms = NULL;
		new->shortest_paths = create_list(NULL);
	}
	return (new);
}

void	destroy_graph(t_graph *graph)
{
	destroy_list_room(graph->rooms);
	destroy_path_list(graph->shortest_paths);
	free(graph->rooms);
	free(graph);
}

int	is_graph_correct(t_graph *graph)
{
	if (graph->rooms->data == NULL)
		return (E_NO_NODE);
	else if (graph->start == NULL)
		return (E_MISSING_START);
	else if (graph->end == NULL)
		return (E_MISSING_END);
	return (E_NO_ERROR);
}
