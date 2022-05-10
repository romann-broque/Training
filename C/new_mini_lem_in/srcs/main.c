/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:55:55 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 11:41:41 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_result	mini_lem_in(const char *path_file)
{
	t_graph		graph;
	t_result	rt_value;

	init_graph(&graph);
	set_graph(&graph);
	rt_value = E_INCOMPLETE_GRAPH;
	if (read_file(path_file, get_inst) == EXIT_SUCCESS
		&& is_graph_complete(&graph))
	{
		get_shortest_paths(&graph);
		display_graph(&graph);
		rt_value = E_NO_ERROR;
	}
	error_manager(rt_value);
	destroy_graph(&graph);
	ft_bzero(&graph, sizeof(graph));
	return (rt_value);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		return (mini_lem_in(av[1]));
	return (EXIT_SUCCESS);
}
