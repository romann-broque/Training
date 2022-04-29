/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:55:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/29 10:26:25 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

#include <stdio.h>

static bool	is_valid_arg(char *arg, const char *pattern)
{
	return (ft_strlen(arg) > 0 && ft_strchr(arg, *pattern) == NULL);
}

result	start(t_graph *graph, const char *command)
{
	char	*arg;
	t_room	*new;
	result	rt_value;

	rt_value = EXIT_FAILURE;
	arg = ft_strdup(command + ft_strlen(START_PATTERN));
	if (graph->start == NULL && is_valid_arg(arg, START_PATTERN) == true)
	{
		find_or_add(&graph->rooms, &new, arg);
		graph->start = new;
		rt_value = EXIT_SUCCESS;
	}
	free(arg);
	return (rt_value);
}

result	end(t_graph *graph, const char *command)
{
	char	*arg;
	t_room	*new;
	result	rt_value;

	rt_value = EXIT_FAILURE;
	arg = ft_strdup(command + ft_strlen(END_PATTERN));
	if (graph->end == NULL && is_valid_arg(arg, END_PATTERN) == true)
	{
		find_or_add(&graph->rooms, &new, arg);
		graph->end = new;
		rt_value = EXIT_SUCCESS;
	}
	free(arg);
	return (rt_value);
}

result	ft_link(t_graph *graph, const char *command)
{
	char	*arg1;
	char	*arg2;
	t_room	*room1;
	t_room	*room2;
	result	rt_value;

	arg1  = ft_strtok(command, DELIM);
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
