/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:55:53 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/22 17:42:04 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**init_grid(char **arg)
{
	char **grid;
	size_t	i;
	size_t	j;

	i = 0;
	grid = (char **)malloc((SIZE_GRID + 1) * sizeof(char *));
	if (grid != NULL)
	{
		while (i < SIZE_GRID)
		{
			j = 0;
			grid[i] = (char *)malloc((SIZE_GRID + 1) * sizeof(char));
			if (arg[i] == NULL)
			{
				desalloc(grid, SIZE_GRID + 1);
				break;
			}
			while (arg[i + 1][j] != '\0')
			{
				grid[i][j] = arg[i + 1][j];
				++j;
			}
			++i;
		}
		grid[i] = NULL;
	}
	return (grid);
}

size_t	*init_coord()
{
	size_t *coord;

	coord = (size_t *)malloc(2 * sizeof(size_t));
	if (coord != NULL)
	{
		coord[0] = 0;
		coord[1] = 0;
	}
	return (coord);
}
