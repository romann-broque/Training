/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:54:41 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 23:10:02 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

result	read_file(const char *path_file, result (*function)(const char *))
{
	int		fd;
	char	*line;
	result	rt_value;

	fd = open(path_file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		rt_value = function(line);
		if (rt_value == EXIT_FAILURE)
			return (EXIT_FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
