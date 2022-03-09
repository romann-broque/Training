/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:55:03 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/09 11:32:02 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_EQ_H

#	include "ft_eight_queens.h"
#	define	FT_EQ_H

#endif

int	prev_pos(int position)
{
	int lign = position / 10;
	int	column = position % 10;

	if (column > 0)
		--column;
	else
	{
		column = SIZE - 1;
		if (lign > 0)
			--lign;
	}
	return (10 * lign + column);
}

int	next_pos(int position)
{
	int lign = position / 10;
	int	column = position % 10;

	if (column < SIZE - 1)
		++column;
	else
	{
		column = 0;
		if (lign <= SIZE - 1)
			++lign;
	}
	return (10 * lign + column);
}

int	last_queen(char **chessboard, int position)
{
	int	lign;
	int	column;

	position = prev_pos(position);
	lign = position / 10;
	column = position % 10;
	while (is_in_chessboard(position))
	{
		if (chessboard[lign][column] == QUEEN)
			return (position);
		if (position == 0)
			break;
		position = prev_pos(position);
		lign = position / 10;
		column = position % 10;
	}
	return (LAST_QUEEN_DOESNT_EXIST);
}

void	turn_into(char **chessboard, int position, char new_c)
{
	const int	lign = position / 10;
	const int	column = position % 10;

	chessboard[lign][column] = new_c;
}
