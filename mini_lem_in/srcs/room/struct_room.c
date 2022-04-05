/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:16:33 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/05 10:24:54 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_list	*create_list_room(char *name)
{
	t_list *new_l;
	t_room *new_r;

	new_r = create_room(name);
	new_l = create_list(new_r);
	return (new_l);
}

t_room	*create_room(char *name)
{
	t_room	*new;

	new = (t_room *)malloc(sizeof(t_room));
	if (new != NULL)
	{
		new->name = name;
		new->lock = false;
		new->neighboor = NULL;
	}
	return (new);
}

void	add_neighboor(t_room *n1, t_room *new)
{
	if (n1->neighboor == NULL)
		n1->neighboor = create_list(new);
	else
		add(n1->neighboor, new);
}

void	add_room(t_list *list, char *name)
{
	t_room	*new_r;

	new_r = create_room(name);
	add(list, new_r);
}

void	destroy_room(t_room *room)
{
	free(room->name);
	destroy_list(&room->neighboor);
	free(room);
}

void	destroy_list_room(t_list *room)
{
	if (room != NULL)
	{
		if (room->next != NULL)
		{
			destroy_list_room(room->next);
			free(room->next);
			destroy_room(room->data);
		}
	}
}

t_room	*find_room(t_list *list, char *name)
{
	if (list != NULL)
	{
		if (are_same_str(((t_room *)(list->data))->name, name) == true)
			return (list->data);
		return (find_room(list->next, name));
	}
	return (NULL);
}

bool	does_room_exist(t_graph *graph, char *name)
{
	t_list	*list;
	t_room	*curr_room;

	list = graph->rooms;
	while (list != NULL)
	{
		curr_room = list->data;
		if (curr_room == NULL)
			break;
		if (are_same_str(curr_room->name, name) == true)
			return (true);
		list = list->next;
	}
	return (false);
}
