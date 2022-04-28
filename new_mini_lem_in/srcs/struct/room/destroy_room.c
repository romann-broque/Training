/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:49:27 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 16:58:22 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	destroy_room(t_room **room)
{
	destroy(&(*room)->name, full_free);
	destroy_list(&(*room)->neighboor, NULL);
	destroy(room, full_free);
}
