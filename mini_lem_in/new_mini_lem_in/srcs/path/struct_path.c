/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:32:05 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/28 18:34:59 by romannbroque     ###   ########.fr       */
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
		new->step = create_list(first_room);
	}
	return (new);
}

t_list	*init_path_list(t_room *start)
{
	t_path	*first_path;
	t_list	*path_list;

	first_path = create_path(start);
	path_list = create_list(first_path);
	return (path_list);
}

void	add_step(t_path *path, t_room *new)
{
	add(path->step, new);
	path->size++;
}

t_room	*get_last_room(t_path *path)
{
	t_room	*last;
	t_list	*list;

	list = path->step;
	last = list->data;
	list = list->next;
	while (list != NULL)
	{
		last = list->data;
		list = list->next;
	}
	return (last);
}

/*
void	keep_shortest_paths(t_list *path_list)
{
	t_path	*curr_path;
	size_t	min_size;

	curr_path = (t_path *)path_list->data;
	min_size = curr_path->size;
	while (curr_path != NULL)
	{
		if (min_size < curr_path->size)
			
		curr_path = curr
	}
}
*/

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
