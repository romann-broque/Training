/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_gallery.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:41:36 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/23 10:15:30 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_gallery	*create_gallery(void *id)
{
	t_gallery	*new;

	new = (t_gallery *)malloc(sizeof(t_gallery));
	if (new != NULL)
	{
		new->room = create_room(id);
		new->link = NULL;
	}
	return (new);
}

void		add_gallery(t_gallery *head, void *id)
{
	t_gallery	*new;

	if (head->link != NULL)
		add_gallery(head->link, id);
	else
	{
		new = create_gallery(id);
		head->link = new;
	}
}
