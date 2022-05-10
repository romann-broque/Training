/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:54:41 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 11:37:16 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

t_result	read_file(const char *path_file, t_result (*function)(const char *))
{
	int			fd;
	char		*line;
	t_result	rt_value;

	fd = open(path_file, O_RDONLY);
	line = get_next_line(fd);
	rt_value = EXIT_SUCCESS;
	while (line != NULL)
	{
		rt_value = function(line);
		free(line);
		if (rt_value != EXIT_SUCCESS)
			break ;
		line = get_next_line(fd);
	}
	close(fd);
	return (rt_value);
}
