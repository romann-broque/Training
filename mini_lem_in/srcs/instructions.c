/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:54:42 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/23 13:45:57 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	inst(char *line, t_gallery **rooms, char *path[2])
{
	char	*arg;

	if (is_start_inst(line))
	{
		arg = get_arg_from_str(line + str_len(START_PATTERN), '\0');
		return (start(arg, path));
	}
	else if (is_end_inst(line))
	{
		arg = get_arg_from_str(line + str_len(END_PATTERN), '\0');
		return (end(arg, path));
	}
	else if (is_link_inst(line))
		return(link_room(line, rooms));
	else
		return (EXIT_FAILURE);
}

int	start(char *arg, char *path[2])
{
	if (path[0] == NULL)
	{
		path[0] = arg;
		printf("START : %s\n", arg);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

int	end(char *arg, char *path[2])
{
	if (path[1] == NULL)
	{
		path[1] = arg;
		printf("END : %s\n", arg);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	link_room(char *line, t_gallery **rooms)
{
	t_room	*head;
	t_room	*new;
	char	*arg1;
	char	*arg2;

	head = create_room(NULL);
	arg1 = get_arg_from_str(line, *DELIM);
	arg2 = get_arg_from_str(line + str_len(arg1) + str_len(DELIM), '\0');
	if (is_room_exist(*rooms, arg1) == false)
	{
		if ((*rooms)->room->id == NULL)
			*rooms = create_gallery(arg1);
		else
			add_gallery(*rooms, arg1);
	}
	if (is_room_exist(*rooms, arg2) == false)
		add_gallery(*rooms, arg2);
	head = find_room(*rooms, arg1);
	new = find_room(*rooms, arg2);
	head = add_room(head, new);
	return (EXIT_SUCCESS);
}
