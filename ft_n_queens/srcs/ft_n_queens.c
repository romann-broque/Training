/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_queens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:10:47 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/09 17:12:44 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EQ_H

#	include "ft_n_queens.h"
#	define	FT_EQ_H

#endif

int	ft_n_queens(void)
{
	char	**chessboard;
	int		position;
	int		queen;

	chessboard = init_chessboard();
	position = 0;
	queen = 0;
	return (back_tracking(chessboard, position, queen));
}

int	main(void)
{
	printf("There are %d distinct solutions.\n",
						ft_n_queens());
	return (EXIT_SUCCESS);
}

