/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_paths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:03:37 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/01 11:50:31 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	find_shortest_paths(void)
{
	int			fd;
	char		*line;
	int			instruction;
	t_graph		*graph;

	graph = init_graph();
	fd = open(PATH_FILE, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		instruction = inst(graph, line);
		if (instruction != E_NO_ERROR)
		{
			display_error(instruction);
			return (EXIT_FAILURE);
		}
		line = get_next_line(fd);
	}
	if (is_graph_correct(graph) != E_NO_ERROR)
	{
		display_error(is_graph_correct(graph));
		return (EXIT_FAILURE);
	}
	close(fd);
	get_shortest_paths(graph);
	display_graph(graph);
	destroy_graph(graph);
	return (EXIT_SUCCESS);
}
