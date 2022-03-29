/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:54:42 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/28 16:26:12 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	inst(t_graph *graph, char *line)
{
	char	*arg;

	if (is_start_inst(line))
	{
		arg = get_arg_from_str(line + str_len(START_PATTERN), '\0');
		return (start(graph, arg));
	}
	else if (is_end_inst(line))
	{
		arg = get_arg_from_str(line + str_len(END_PATTERN), '\0');
		return (end(graph, arg));
	}
	else if (is_link_inst(line))
		return (link_room(graph, line));
	else
		return (EXIT_FAILURE);
}

int	start(t_graph *graph, char *arg)
{
	if (graph->start == NULL)
	{
		graph->start = find_room(graph->rooms, arg);
		graph->shortest_paths = init_path_list(graph->start);
		if (graph->start == NULL)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

int	end(t_graph *graph, char *arg)
{
	if (graph->end == NULL)
	{
		graph->end = find_room(graph->rooms, arg);
		if (graph->end == NULL)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	link_room(t_graph *graph, char *line)
{
	t_room	*head;
	t_room	*new;
	char	*arg1;
	char	*arg2;

	head = create_room(NULL);
	arg1 = get_arg_from_str(line, *DELIM);
	arg2 = get_arg_from_str(line + str_len(arg1) + str_len(DELIM), '\0');
	if (does_room_exist(graph, arg1) == false)
	{
		if (graph->rooms->data == NULL)
			graph->rooms = create_list_room(arg1);
		else
			add_room(graph->rooms, arg1);
	}
	if (does_room_exist(graph, arg2) == false)
		add_room(graph->rooms, arg2);
	head = find_room(graph->rooms, arg1);
	new = find_room(graph->rooms, arg2);
	head = add_neighboor(head, new);
	return (EXIT_SUCCESS);
}
