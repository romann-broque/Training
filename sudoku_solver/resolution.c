/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:56:22 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/16 23:21:39 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//unsigned int sum_number_from_str(char *grid)

void	try_next_number(char **grid, size_t line_index, size_t column_index)
{
	char	number;

	number = grid[line_index][column_index];
	if ((number == UNKNOWN) || (number > '0' + SIZE_GRID))
		number = '0';
	number += 1;
	grid[line_index][column_index] = nb;
}

void	sudoku_solver(char **grid, size_t line_index, size_t column_index)
{
	while (is_still_unknown(grid))
	{
		if ((grid[line_index][column_index] == UNKNOWN)
			|| (is_correct(grid, line_index, column_index) == false))
		{
			try_next_number(grid, line_index, column_index);
			sudoku_solver(grid, line_index, column_size);
		}
		else if (is_correct(grid, line_index, column_index) == true)
		{
			if (column_index < SIZE_GRID - 1)
					++column_index;
			else
			{
				column_index = 0;
				if (line_index >= SIZE_GRID - 1)
					break;
				++line_index;
			}
		}
	}
}
