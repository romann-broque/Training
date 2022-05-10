/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:42:19 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 23:11:38 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_n_queens.h"

int	back_tracking(char **chessboard, int position, int queen)
{
	int	count;

	if (queen == QUEEN_NB)
	{
		display_chessboard(chessboard);
		return (1);
	}
	count = 0;
	while (is_in_chessboard(position))
	{
		if (is_case_valid(chessboard, position))
		{
			add_queen(chessboard, position);
			count += back_tracking(chessboard, next_pos(position), queen + 1);
			remove_queen(chessboard, position);
		}
		position = next_pos(position);
	}
	return (count);
}
