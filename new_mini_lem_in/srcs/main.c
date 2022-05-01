/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:55:55 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 00:15:44 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	main(int ac, char **av)
{
	char	*path_file;
	t_graph	graph;
	result	rt_value;

	rt_value = EXIT_FAILURE;
	if (ac > 1)
	{
		path_file = av[1];
		init_graph(&graph);
		set_graph(&graph);
		if (read_file(path_file, get_inst) == EXIT_SUCCESS && is_graph_complete(&graph))
		{
			get_shortest_paths(&graph);
			display_graph(&graph);
			rt_value = EXIT_SUCCESS;
		}
		destroy_graph(&graph);
	}
	ft_bzero(&graph, sizeof(graph));
	return (rt_value);
}
