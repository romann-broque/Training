/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:42:19 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/08 17:06:02 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_EQ_H

#	include "ft_eight_queens.h"
#	define	FT_EQ_H

#endif

bool	back_tracking(char **chessboard, int position)
{
	int	last_queen_pos;

	while (is_count_queens(chessboard) < QUEEN_NB)
	{
		if (is_valid(chessboard, position) == false)
		{
			if (is_in_chessboard(position) == false)
			{
				last_queen_pos = last_queen(chessboard, position);
				if (last_queen_pos == LAST_QUEEN_DOESNT_EXIST)
					return(false);
				position = last_queen_pos;
				turn_into(chessboard, position, EMPTY);
				return (back_tracking(chessboard, next_pos(position)));
			}
			else
				position = next_pos(position);
		}
		else
		{
			turn_into(chessboard, position, QUEEN);
			position = next_pos(position);
		}
	}
	return (true);
}
