/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:03:48 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/16 22:25:47 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//bool	is_solution_unique(char **grid)
//bool	is_still_unknown(char **grid)

bool	is_line_correct(char *line)
{
	return (sum_number_from_str(line) == SUM)
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
		return (sum_number_from_str(column) == SUM);
	}
	return (false);
}

//bool	is_block_correct(char **grid, size_t line_index, size_t column_index)

bool	is_correct(char **grid, size_t line_index, size_t column_index)
{
	return ((is_line_correct(grid[line_index]))
			&& (is_column_correct(grid, line_index, column_index))
			&& (is_block_correct(grid, line_index, column_index))
}
