/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:56:22 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/22 18:59:29 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	go_forward(size_t *coord)
{
	if (coord[1] < SIZE_GRID - 1)
		++coord[1];
	else
	{
		coord[1] = 0;
		if (coord[0] == SIZE_GRID - 1)
			return (false);
		++coord[0];
	}
	return (true);
}

void	go_back_to_last_changed_number(char **orig_grid, char **curr_grid, size_t *coord)
{
	while (can_be_changed(orig_grid, curr_grid, coord) == false)
	{
		if (coord[1] > 0)
			--coord[1];
		else if (coord[0] > 0)
		{
			coord[1] = SIZE_GRID - 1;
			--coord[0];
		}
	}
}

void	sudoku_solver(char **orig_grid, char **curr_grid, size_t *coord)
{
	while ((is_still_unknown(curr_grid) == true) || (is_correct(curr_grid, coord) == false))
	{
		if (curr_grid[coord[0]][coord[1]] == UNKNOWN)
			curr_grid[coord[0]][coord[1]] = '1';
		else if (is_correct(curr_grid, coord) == false)
		{
			if (can_be_changed(orig_grid, curr_grid, coord) == true)
				++curr_grid[coord[0]][coord[1]];
			else
			{
				curr_grid[coord[0]][coord[1]] = UNKNOWN;
				go_back_to_last_changed_number(orig_grid, curr_grid, coord);
				++curr_grid[coord[0]][coord[1]];
				sudoku_solver(orig_grid, curr_grid, coord);
			}
		}
		else
		{
			if (go_forward(coord) == false)
				break;
		}
	}
}
