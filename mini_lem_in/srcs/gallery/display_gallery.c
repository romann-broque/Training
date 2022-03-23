/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gallery.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:23:50 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/22 18:06:43 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	display_gallery(t_gallery *head)
{
	t_room		*curr_room;
	t_node		*sub_room;

	if (head != NULL)
	{
		curr_room = head->room;
		printf("%s : ", curr_room->id);
		sub_room = curr_room->link;
		if (sub_room != NULL)
			display_list_room(sub_room);
		printf("\n");
		display_gallery(head->link);
	}
}
