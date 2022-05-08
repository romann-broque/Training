/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:20:18 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 16:55:02 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maze.h"

size_t	count_lines(const char *path_file)
{
	int		fd;
	size_t	count;
	char	*line;

	fd = open(path_file, O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		++count;
	}
	close(fd);
	return (count);	
}

size_t	max_len(const char *path_file)
{
	int		fd;
	size_t	max;
	size_t	curr;
	char	*line;

	fd = open(path_file, O_RDONLY);
	line = get_next_line(fd);
	max = 0;
	while (line != NULL)
	{
		curr = ft_strlen(line);
		if (curr > max)
			max = curr;
		line = get_next_line(fd);
	}
	return (max);
}

char	*init_map(const char *path_file)
{
	int		fd;
	char	*map;
	char	*line;

	fd = open(path_file, O_RDONLY);
	map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map = ft_strcat(map, line);
		line = get_next_line(fd);
	}
	return (map);
}

char	get_x(const char *map, size_t coord, size_t max_width)
{
	return (map[coord / max_width]);
}

char	get_y(const char *map, size_t coord, size_t max_depth)
{
	return (map[coord % max_depth]);
}
