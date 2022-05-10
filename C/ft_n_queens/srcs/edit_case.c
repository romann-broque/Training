/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:05:20 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 23:11:59 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_n_queens.h"

void	turn_into(char **chessboard, int position, char new_c)
{
	const int	lign = get_lign(position);
	const int	column = get_column(position);

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

