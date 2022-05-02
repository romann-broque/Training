/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:55:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 19:51:35 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_result	start(t_graph *graph, const char *command)
{
	t_room		*new;
	t_result	rt_value;

	rt_value = EXIT_FAILURE;
	if (graph->start == NULL)
	{
		find_or_add(&graph->rooms, &new, command);
		graph->start = new;
		rt_value = EXIT_SUCCESS;
	}
	return (rt_value);
}

t_result	end(t_graph *graph, const char *command)
{
	t_room		*new;
	t_result	rt_value;

	rt_value = EXIT_FAILURE;
	if (graph->end == NULL)
	{
		find_or_add(&graph->rooms, &new, command);
		graph->end = new;
		rt_value = EXIT_SUCCESS;
	}
	return (rt_value);
}

t_result	ft_link(t_graph *graph, const char *command)
{
	char		*arg1;
	char		*arg2;
	t_room		*room1;
	t_room		*room2;
	t_result	rt_value;

	arg1 = ft_strtok(command, DELIM);
	arg2 = ft_strdup(command + ft_strlen(arg1) + ft_strlen(DELIM));
	rt_value = EXIT_FAILURE;
	if (is_valid_arg(arg1, DELIM) && is_valid_arg(arg2, DELIM))
	{
		find_or_add(&graph->rooms, &room1, arg1);
		find_or_add(&graph->rooms, &room2, arg2);
		add_element(&room1->neighboor, room2);
		rt_value = EXIT_SUCCESS;
	}
	free(arg1);
	free(arg2);
	return (rt_value);
}
