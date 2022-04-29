/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_graph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:51:10 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/29 11:51:28 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

bool	is_graph_complete(t_graph *graph)
{
	return (graph->start != NULL
			&& graph->end != NULL
			&& graph->rooms != NULL);
}
