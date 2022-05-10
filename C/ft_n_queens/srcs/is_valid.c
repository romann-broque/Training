/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:38:56 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 23:12:59 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_n_queens.h"

bool is_column_valid(char **chessboard, int position)
{
	size_t		i;
	const int	column = get_column(position);

	i = 0;
	while (i < SIZE)
	{
		if (chessboard[i][column] == QUEEN)
			return(false);
		++i;
	}
	return (true);
}

static bool	is_the_same_diag(int direction, int first_column, int curr_column)
{
	if (direction == 1)
		return (curr_column >= first_column);
	return (curr_column <= first_column);
}

static bool	is_diag_valid(char **chessboard, int pos,
		const int direction[2])
{
	const int	offset = SIZE * direction[0] + direction[1];
	const int	first_column = get_column(pos);

	while (is_in_chessboard(pos)
		&& is_the_same_diag(direction[1], first_column, get_column(pos)))
	{
		if (read_case(chessboard, pos) == QUEEN)
			return (false);
		pos += offset;
	}
	return (true);
}

bool are_diags_valid(char **chessboard, int position)
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
	const int	lign = get_lign(position);

	return (is_in_chessboard(position)
			&&(is_queen(chessboard[lign]) == false)
			&& is_column_valid(chessboard, position)
			&& are_diags_valid(chessboard, position));
}
