/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:03:48 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/22 18:28:32 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//bool	is_solution_unique(char **grid)

bool	can_be_changed(char **orig_grid, char **curr_grid, size_t *coord)
{
	char	nb;

	nb = curr_grid[coord[0]][coord[1]];
	if (orig_grid[coord[0]][coord[1]] == UNKNOWN)
	{
		if ((nb > '0') && (nb < '9'))
			return (true);
	}
	return (false);
}

bool	is_str_correct(const char *str)
{
	if (are_double_numbers(str) == false)
	{
		if ((is_strchr(str, UNKNOWN) == true)
			|| (sum_number_from_str(str) == SUM))
			return (true);
	}
	return (false);
}

bool	is_line_correct(char *line)
{
	return (is_str_correct(line));
}

bool	is_column_correct(char **grid, size_t column_index)
{
	size_t	i;
	char	*column;

	i = 0;
	column = (char *)malloc((SIZE_GRID + 1) * sizeof(char));
	if (column != NULL)
	{
		column[SIZE_GRID] = '\0';
		while (i < SIZE_GRID)
		{
			column[i] = grid[i][column_index];
			++i;
		}
		return (is_str_correct(column));
	}
	return (false);
}

bool	is_block_correct(char **grid, size_t *coord)
{
	size_t	i;
	size_t	max_line_index;
	size_t	j;
	size_t	max_column_index;
	size_t	k;
	char	*block;

	block = (char *)malloc((SIZE_GRID + 1) * sizeof(char));
	if (block != NULL)
	{
		i = (coord[0] / 3) * 3;
		max_line_index = i + 3;
		j = (coord[1] / 3) * 3;
		max_column_index = j + 3;
		k = 0;
		while (i < max_line_index)
		{
			j = (coord[1] / 3) * 3;
			while (j < max_column_index)
			{
				block[k] = grid[i][j];
				printf("\n%c\n", block[k]);
				++j;
				++k;
			}
			++i;
		}
		block[SIZE_GRID] = '\0';
		printf("\n\n%s\n", block);
		return (is_str_correct(block));
	}
	return (false);
}

bool	is_correct(char **grid, size_t *coord)
{
	return ((is_line_correct(grid[coord[0]]))
			&& (is_column_correct(grid, coord[1]))
			&& (is_block_correct(grid, coord)));
}
