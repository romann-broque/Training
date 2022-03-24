/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:49:58 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/24 12:03:40 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	main(void)
{
	int			fd;
	int			instruction;
	char		*line;
	char		*path[2];
	t_graph		*graph;

	fd = open(PATH_FILE, O_RDONLY);
	path[0] = NULL;
	path[1] = NULL;

	graph = init_graph();

	line = get_next_line(fd);
	while (line != NULL)
	{
		instruction = inst(graph, line, path);
		if (instruction == EXIT_FAILURE)
		{
			display_error(instruction);
			return (EXIT_FAILURE);
		}
		line = get_next_line(fd);
	}
	close(fd);
	display_list(graph->rooms);
	printf("\n");
	return (EXIT_SUCCESS);
}
