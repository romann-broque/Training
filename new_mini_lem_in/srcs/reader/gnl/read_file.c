/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:54:41 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/27 16:35:57 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	read_file(const char *path_file, void (*function)(const char *))
{
	int		fd;
	char	*line;

	fd = open(path_file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		function(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
