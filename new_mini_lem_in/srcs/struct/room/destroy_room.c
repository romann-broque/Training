/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:49:27 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 14:55:29 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	destroy_room(t_room *room)
{
	destroy(room->name, full_free);
	destroy_list(&room->neighboor, full_free);
	destroy(room, full_free);
}
