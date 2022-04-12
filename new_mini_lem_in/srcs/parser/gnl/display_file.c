/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:42:41 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/12 15:40:53 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	display_file(const char *path_file)
{
	int		fd;
	char	*line;

	fd = open(path_file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_putstr(line);
		line = get_next_line(fd);
	}
	close(fd);
}
