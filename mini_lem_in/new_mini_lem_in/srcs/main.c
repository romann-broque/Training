/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:49:58 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/28 18:35:15 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	main(void)
{
	int			fd;
	char		*line;
	int			instruction;
	t_graph		*graph;

	fd = open(PATH_FILE, O_RDONLY);

	graph = init_graph();

	line = get_next_line(fd);
	while (line != NULL)
	{
		instruction = inst(graph, line);
		if (instruction == EXIT_FAILURE)
		{
			display_error(instruction);
			return (EXIT_FAILURE);
		}
		line = get_next_line(fd);
	}
	close(fd);
	if (graph->start == NULL || graph->end == NULL)
		return (EXIT_FAILURE);
	display_graph(graph);
	printf("\n");
	display_shortest_paths(graph);
	return (EXIT_SUCCESS);
}
