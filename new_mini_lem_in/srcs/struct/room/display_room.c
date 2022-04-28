/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:37:18 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 17:58:35 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	display_room(t_room *room)
{
	if (room != NULL)
	{
		if (room->name != NULL)
			ft_putstr(room->name);
	}
}

void	full_display_room(t_room *room)
{
	display_room(room);
	ft_putstr(" : ");
	display_list(&room->neighboor, display_room);
}
