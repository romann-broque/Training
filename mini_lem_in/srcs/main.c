/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:49:58 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/16 18:28:13 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open(PATH_FILE, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		inst(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
