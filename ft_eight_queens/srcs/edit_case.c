/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:05:20 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/09 17:12:31 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_EQ_H

#	include "ft_n_queens.h"
#	define	FT_EQ_H

#endif

int	next_pos(int position)
{
	int lign;
	int	column;
	int	next_pos;

	lign = position / 10;
	column = position % 10;
	if (column < SIZE - 1)
		++column;
	else
	{
		column = 0;
		if (lign <= SIZE - 1)
			++lign;
	}
	next_pos = 10 * lign + column;
	return (next_pos);
}

void	turn_into(char **chessboard, int position, char new_c)
{
	const int	lign = position / 10;
	const int	column = position % 10;

	chessboard[lign][column] = new_c;
}

void add_queen(char **chessboard, int position)
{
	turn_into(chessboard, position, QUEEN);
}

void remove_queen(char **chessboard, int position)
{
	turn_into(chessboard, position, EMPTY);
}

