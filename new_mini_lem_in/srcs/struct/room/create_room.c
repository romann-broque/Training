/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:14:39 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 18:44:04 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_room	*create_room(const char *input_name, t_list *list)
{
	t_room	*new;

	new = (t_room *)malloc(sizeof(t_room));
	if (new != NULL)
	{
		new->name = ft_strdup(input_name);
		new->neighboor = list;
	}
	return (new);
}

void	create_n_add_room(t_list **list, t_room **room, const char *name)
{
	*room = create_room(name, NULL);
	add_element(list, *room);
}
