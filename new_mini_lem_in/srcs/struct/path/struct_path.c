/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:44:01 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 11:31:09 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

static t_list	*get_deep_cp_path(t_list *path)
{
	t_list	*cp;

	cp = NULL;
	if (path != NULL)
		cp = create_list(path->data, get_deep_cp_path(path->next));
	return (cp);
}

static void	keep_shortest_paths(t_list *path_list, t_list *new_path)
{
	const size_t	new_size = get_size_list(new_path);
	size_t			curr_size;
	t_list			*curr_path;
	
	curr_path = path_list->data;
	curr_size = get_size_list(curr_path);
	if (new_size <= curr_size)
	{
		if (new_size < curr_size)
			destroy_list(&path_list, destroy_list_rec);
		add_element(&path_list, new_path);
	}
}

void		extract_path(t_graph *graph, t_list **path)
{
	t_list	*cp_path;

	cp_path = get_deep_cp_path(*path);
	if (graph->shortest_paths == NULL)
		graph->shortest_paths = create_list(cp_path, NULL);
	else
		keep_shortest_paths(graph->shortest_paths, cp_path);
}
