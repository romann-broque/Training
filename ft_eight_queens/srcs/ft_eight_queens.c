/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:44:52 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/09 08:58:02 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EQ_H

#	include "ft_eight_queens.h"
#	define	FT_EQ_H

#endif

void	ft_eight_queens(void)
{
	char			**chessboard;
	size_t			fst_pos;
	int				count_sol;
	const size_t	size = SIZE * SIZE;

	fst_pos = 0;
	count_sol = 0;
	while (fst_pos < size)
	{
		chessboard = init_chessboard();
		printf("\n");
		count_sol += back_tracking(chessboard, fst_pos);
		display_chessboard(chessboard);
		fst_pos = next_pos(fst_pos);
	}
	return (count_sol);
}

int	main(void)
{
	printf("There are %d solutions\n", ft_eight_queens());
	return (EXIT_SUCCESS);
}

