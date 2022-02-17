/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 23:19:04 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/16 23:20:07 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	size_t	i;
	char	**grid;
	const char	*completed_grid =

"9 1 4 3 7 5 2 6 8\n\
2 8 7 4 9 6 1 5 3\n\
3 6 5 8 1 2 4 7 9\n\
8 4 6 5 2 1 3 9 7\n\
5 2 9 6 3 7 8 1 4\n\
7 3 1 9 8 4 5 2 6\n\
1 5 3 7 4 9 6 8 2\n\
6 9 8 2 5 3 7 4 1\n\
4 7 2 1 6 8 9 3 5\n";

	grid = NULL;
	if (ac > 9)
	{
		i = 0;
		grid = init_grid(grid, av);
		printf("To solve : \n\n");
		while (grid[i] != NULL)
		{
			printf("%s\n", grid[i]);
			++i;
		}
		printf("\nSolved : \n\n%s\n", completed_grid);
	}
	return (EXIT_SUCCESS);
}
