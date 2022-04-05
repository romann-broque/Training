/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:54:42 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/05 11:18:35 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	inst(t_graph *graph, char *line)
{
	char	*arg;
	int		id;

	arg = NULL;
	id = E_UNKNOWN_COMMAND;
	if (is_start_inst(line))
	{
		arg = get_arg_from_str(line + ft_strlen(START_PATTERN), '\0');
		id = start(graph,arg);
	}
	else if (is_end_inst(line))
	{
		arg = get_arg_from_str(line + ft_strlen(END_PATTERN), '\0');
		id = end(graph, arg);
	}
	else if (is_link_inst(line))
		id = link_room(graph, line);
	free(arg);
	return (id);
}

int	start(t_graph *graph, char *arg)
{
	if (graph->rooms->data != NULL)
	{
		if (graph->start == NULL)
		{
			graph->start = find_room(graph->rooms, arg);
			if (graph->start == NULL)
				return (E_START_DOESNT_EXIST);
			return (E_NO_ERROR);
		}
		else
			return (E_START_NOT_UNIQUE);
	}
	return (E_NO_NODE);
}

int	end(t_graph *graph, char *arg)
{
	if (graph->rooms->data != NULL)
	{
		if (graph->end == NULL)
		{
			graph->end = find_room(graph->rooms, arg);
			if (graph->end == NULL)
				return (E_END_DOESNT_EXIST);
			return (E_NO_ERROR);
		}
		return (E_END_NOT_UNIQUE);
	}
	return (E_NO_NODE);
}

int	link_room(t_graph *graph, char *line)
{
	t_room	*head;
	t_room	*new;
	char	*arg1;
	char	*arg2;

	arg1 = get_arg_from_str(line, *DELIM);
	arg2 = get_arg_from_str(line + ft_strlen(arg1) + ft_strlen(DELIM), '\0');
	if (does_room_exist(graph, arg1) == false)
	{
		if (graph->rooms->data == NULL)
		{
			free(graph->rooms);
			graph->rooms = create_list_room(arg1);
		}
		else
			add_room(graph->rooms, arg1);
	}
	if (does_room_exist(graph, arg2) == false)
		add_room(graph->rooms, arg2);
	head = find_room(graph->rooms, arg1);
	new = find_room(graph->rooms, arg2);
	add_neighboor(head, new);
	return (E_NO_ERROR);
}
