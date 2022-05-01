/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:32:00 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 00:24:04 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	destroy_graph(t_graph *graph)
{
	destroy_list(&graph->rooms, destroy_room);
	destroy_list(&graph->shortest_paths, destroy_list_rec);
}
