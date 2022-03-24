/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:14:09 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/24 12:33:44 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

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

t_room	*add_room(t_room *n1, t_room *new)
{
	if (n1->neighboor != NULL)
		add(n1->neighboor, new);
	else
		n1->neighboor = create_list(new);
	return (n1);
}

t_room	*find_room(t_list *curr, void *id)
{
	if (curr != NULL)
	{
		if (are_same_str((char *)(((t_room *)(curr->data))->name), (char *)id) == true)
			return (curr->data);
		return (find_room(curr->next, id));
	}
	return (NULL);
}

bool	is_room_exist(t_list *curr, void *name)
{
	if (curr != NULL)
	{
		if (are_same_str((char *)(((t_room *)(curr->data))->name), (char *)name) == true)
			return (true);
		return (is_room_exist(curr->next, name));
	}
	return (false);
}
