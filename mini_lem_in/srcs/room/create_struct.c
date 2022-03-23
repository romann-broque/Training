/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:14:09 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/23 10:11:27 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_room	*create_room(char *name)
{
	t_room	*new;

	new = (t_room *)malloc(sizeof(t_room));
	if (new != NULL)
	{
		new->id = name;
		new->discovered = false;
		new->link = NULL;
	}
	return (new);
}

t_room	*add_room(t_room *n1, t_room *new)
{
	if (n1->link != NULL)
		add(n1->link, new);
	else
		n1->link = create_node(new);
	return (n1);
}

t_room	*find_room(t_gallery *head, void *id)
{
	if (head != NULL)
	{
		if (are_same_str((char *)head->room->id, (char *)id) == true)
			return (head->room);
		return (find_room(head->link, id));
	}
	return (NULL);
}

bool	is_room_exist(t_gallery *head, void *name)
{
	if (head != NULL)
	{
		if (are_same_str((char *)head->room->id, (char *)name) == true)
			return (true);
		return (is_room_exist(head->link, name));
	}
	return (false);
}
