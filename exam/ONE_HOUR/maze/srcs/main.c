/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:59:44 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 16:55:30 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maze.h"

#include <stdio.h>

t_result	maze(const char *path_file)
{
	printf("%zu\n", count_lines(path_file));
	printf("%zu\n", max_len(path_file));
	printf("%s\n", init_map(path_file));
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		return (maze(av[1]));
	return (EXIT_SUCCESS);
}
