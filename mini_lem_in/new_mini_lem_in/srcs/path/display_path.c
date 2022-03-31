/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:19:16 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/30 23:22:22 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	display_path_list(t_list *path_list)
{
	t_list	*curr_l;
	t_path	*curr_p;

	curr_l = path_list;
	curr_p = curr_l->data;
	while (curr_l != NULL && curr_p != NULL)
	{
		curr_p = curr_l->data;
		display_list_room(curr_p->step);
		curr_l = curr_l->next;
	}
}

void	display_shortest_paths(t_graph *graph)
{
	t_list	**first_path;

	first_path = (t_list **)malloc(sizeof(t_list *));
	if (first_path != NULL)
	{
		*first_path = create_list(graph->start);
		path_finder(graph, graph->start, first_path);
		display_path_list(graph->shortest_paths);
	}
}
