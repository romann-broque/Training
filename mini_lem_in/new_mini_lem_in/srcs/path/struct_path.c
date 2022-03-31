/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:32:05 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/31 11:42:43 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_path	*create_path(t_room *first_room)
{
	t_path	*new;

	new = (t_path *)malloc(sizeof(t_path));
	if (new != NULL)
	{
		new->size = 1;
		new->completed = false;
		new->step = create_list(first_room);
	}
	return (new);
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
			curr->next = NULL;
		}
	}
}

t_list	*get_deep_cp_path(t_list *path)
{
	t_list	*cp;

	cp = NULL;
	if (path != NULL)
	{
		cp = create_list(path->data);
		cp->next = get_deep_cp_path(path->next);
	}
	return (cp);
}

void	keep_shortest_paths(t_list *path_list, t_path *new_path)
{
	t_path	*curr_path;

	curr_path = (t_path *)path_list->data;
	if (new_path->size <= curr_path->size)
	{
		if (new_path->size < curr_path->size)
		{
			destroy_list(&path_list);
			path_list = create_list(new_path);
		}
		else
			add(path_list, new_path);
	}
}

void	extract_path(t_graph *graph, t_list **path)
{
	t_list	*cp_step = get_deep_cp_path(*path);
	t_path	*cp_path;

	cp_path = create_path(NULL);
	cp_path->step = cp_step;
	cp_path->size = get_size(&cp_step);
	if (graph->shortest_paths->data == NULL)
		graph->shortest_paths = create_list(cp_path);
	keep_shortest_paths(graph->shortest_paths, cp_path);
}
