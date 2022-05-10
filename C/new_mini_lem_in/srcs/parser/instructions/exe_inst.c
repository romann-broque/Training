/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:55:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 11:58:55 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_result	start(t_graph *graph, const char *command)
{
	t_room		*new;
	t_result	rt_value;

	rt_value = E_START_ERROR;
	if (graph->start == NULL)
	{
		find_or_add(&graph->rooms, &new, command);
		graph->start = new;
		rt_value = E_NO_ERROR;
	}
	return (rt_value);
}

t_result	end(t_graph *graph, const char *command)
{
	t_room		*new;
	t_result	rt_value;

	rt_value = E_END_ERROR;
	if (graph->end == NULL)
	{
		find_or_add(&graph->rooms, &new, command);
		graph->end = new;
		rt_value = E_NO_ERROR;
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
	rt_value = E_INVALID_NAME_ERROR;
	if (is_perfect_arg(arg1) == true && is_perfect_arg(arg2) == true)
	{
		find_or_add(&graph->rooms, &room1, arg1);
		find_or_add(&graph->rooms, &room2, arg2);
		add_element(&room1->neighboor, room2);
		rt_value = E_NO_ERROR;
	}
	free(arg1);
	free(arg2);
	return (rt_value);
}
