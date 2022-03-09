/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:38:56 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/09 17:13:16 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_EQ_H

#	include "ft_n_queens.h"
#	define	FT_EQ_H

#endif

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
	int	lign;
	int	column;

	lign = pos / 10;
	column = pos % 10;
	while (is_in_chessboard(pos))
	{
		if (chessboard[lign][column] == QUEEN)
			return (false);
		lign += direction[0];
		column += direction[1];
		pos = 10 * lign + column;
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

bool	is_case_valid(char **chessboard, int position)
{
	const int	x_coord = position / 10;
	const int	y_coord = position % 10;

	return (is_in_chessboard(position)
			&&(is_queen(chessboard[x_coord]) == false)
			&& is_column_valid(chessboard, y_coord)
			&& are_diags_valid(chessboard, position));
}
