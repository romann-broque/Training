/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:38:30 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 18:13:29 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	display_graph(t_graph *graph)
{
	t_list	*room;

	if (graph != NULL)
	{
		if (graph->start != NULL)
		{
			ft_putstr("START : ");
			ft_putendl(((t_room *)(graph->start))->name);
		}
		if (graph->end != NULL)
		{
			ft_putstr("END : ");
			ft_putendl(((t_room *)(graph->end))->name);
		}
		if (graph->rooms != NULL)
		{
			ft_putstr("\n");
			ft_putendl("ROOMS : \n");
			room = graph->rooms;
			while (room != NULL)
			{
				full_display_room(room->data);
				room = room->next;
			}
		}
	}
}
