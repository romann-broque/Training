/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:38:56 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/08 17:04:00 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_EQ_H

#	include "ft_eight_queens.h"
#	define	FT_EQ_H

#endif

bool	is_in_chessboard(int pos)
{
	const int	lign = pos / 10;
	const int	column = pos % 10;

	return ((lign >= 0) && (lign < SIZE)
			&& (column >= 0) && (column < SIZE));
}

static bool is_column_valid(char **chessboard, int y_coord)
{
	char	*column;
	size_t	i;

	column = (char *)malloc((SIZE + 1) * sizeof(char));
	if (column != NULL)
	{
		i = 0;
		while (i < SIZE)
		{
			column[i] = chessboard[i][y_coord];
			++i;
		}
		column[i] ='\0';
	}
	return (is_queen(column) == false);
}

static bool	is_diag_valid(char **chessboard, int pos,
											const int direction[2])
{
	int	curr_x;
	int	curr_y;

	curr_x = pos / 10;
	curr_y = pos % 10;
	while (is_in_chessboard(pos))
	{
		if (chessboard[curr_x][curr_y] == QUEEN)
			return (false);
		curr_x += direction[0];
		curr_y += direction[1];
		pos = 10 * curr_x + curr_y;
	}
	return (true);
}

static bool are_diags_valid(char **chessboard, int position)
{
	const int	left_up[2] = {-1, -1};
	const int	right_up[2] = {-1, 1};
	const int	left_down[2] = {1, -1};
	const int	right_down[2] = {1, 1};

	return ((is_diag_valid(chessboard, position, left_up))
			&& (is_diag_valid(chessboard, position, right_up))
			&& (is_diag_valid(chessboard, position, left_down))
			&& (is_diag_valid(chessboard, position, right_down)));
}

bool	is_valid(char **chessboard, int position)
{
	const int	x_coord = position / 10;
	const int	y_coord = position % 10;

	return (is_in_chessboard(position)
			&&(is_queen(chessboard[x_coord]) == false)
			&& is_column_valid(chessboard, y_coord)
			&& are_diags_valid(chessboard, position));
}
