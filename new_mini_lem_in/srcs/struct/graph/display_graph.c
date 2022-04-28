/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:38:30 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 11:14:41 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	display_graph(t_graph *graph)
{
	if (graph != NULL)
	{
		if (graph->start != NULL)
		{
			ft_putstr("START : ");
			ft_putendl(graph->start);
		}
		if (graph->end != NULL)
		{
			ft_putstr("END : ");
			ft_putendl(graph->end);
		}
		if (graph->rooms != NULL)
		{
			ft_putstr("ROOMS : ");
			display_list(&graph->rooms, display_room);
		}
	}
}
