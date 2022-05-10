/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_queens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:10:47 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 23:16:32 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_n_queens.h"

int	ft_n_queens(void)
{
	char	**chessboard;
	int		position;
	int		queen;

	if ((QUEEN_NB < 0) || (SIZE <= 0) || (QUEEN_NB > SIZE))
		return (0);
	if (SIZE == 1)
		return (1);
	chessboard = init_chessboard();
	position = 0;
	queen = 0;
	return (back_tracking(chessboard, position, queen));
}
