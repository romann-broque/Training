/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:00:59 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/31 22:07:26 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_graph *init_graph(void)
{
	t_graph	*new;

	new = (t_graph *)malloc(sizeof(t_graph));
	if (new != NULL)
	{
		new->rooms = create_list(NULL);
		new->start = NULL;
		new->end = NULL;
		new->shortest_paths = create_list(NULL);
	}
	return (new);
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
