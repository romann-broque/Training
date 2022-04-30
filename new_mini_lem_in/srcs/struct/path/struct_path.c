/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:44:01 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/30 18:41:50 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_path	*create_path(t_list *rooms)
{
	t_path	*new;

	new = (t_path *)malloc(sizeof(t_path));
	if (new != NULL)
	{
		new->rooms = rooms;
		new->size = get_size_list(rooms);
	}
	return (new);
}

void	destroy_path_list(t_list *path_list)
{
	if (path_list != NULL)
	{
		if (path_list->next != NULL)
			destroy_path_list(path_list->next);
		free(path_list);
	}
}

static t_list	*get_deep_cp_path(t_list *path)
{
	t_list	*cp;

	cp = NULL;
	if (path != NULL)
		cp = create_list(path->data, get_deep_cp_path(path->next));
	return (cp);
}

void	keep_shortest_paths(t_list *path_list, t_path *new_path)
{
	t_path	*curr_path;

	curr_path = (t_path *)path_list->data;
	if (new_path->size <= curr_path->size)
	{
		if (new_path->size < curr_path->size)
			path_list = create_list(new_path, NULL);
		else
			add_element(&path_list, new_path);
	}
}

void	cut_path(t_list **path)
{
	t_list	*curr;

	if (*path != NULL)
	{
		if ((*path)->next != NULL)
		{
			curr = *path;
			while (curr->next->next != NULL)
				curr = curr->next;
			destroy_list(&curr->next, NULL);
		}
	}
}

void	extract_path(t_graph *graph, t_list **path)
{
	t_list	*cp_step;
	t_path	*cp_path;

	cp_step = get_deep_cp_path(*path);
	cp_path = create_path(NULL);
	cp_path->size = get_size_list(cp_step);
	cp_path->rooms = cp_step;
	if (graph->shortest_paths == NULL)
		graph->shortest_paths = create_list(cp_path, NULL);
	else
		keep_shortest_paths(graph->shortest_paths, cp_path);
}
