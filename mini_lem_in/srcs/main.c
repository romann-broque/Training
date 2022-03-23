/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:49:58 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/23 12:01:44 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	main(void)
{
	int			fd;
	int			instruction;
	char		*line;
	char		*path[2];
	t_gallery	*rooms;

	fd = open(PATH_FILE, O_RDONLY);
	path[0] = NULL;
	path[1] = NULL;
	rooms = create_gallery(NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		instruction = inst(line, &rooms, path);
		if (instruction == EXIT_FAILURE)
		{
			display_error(instruction);
			return (EXIT_FAILURE);
		}
		line = get_next_line(fd);
	}
	close(fd);
	display_gallery(rooms);
	printf("\n");
//	bfs(find_room(rooms, path[0]), find_room(rooms, path[1]));	
	return (EXIT_SUCCESS);
}
