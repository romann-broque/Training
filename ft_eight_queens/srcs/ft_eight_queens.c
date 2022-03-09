/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:44:52 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/09 11:14:40 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EQ_H

#	include "ft_eight_queens.h"
#	define	FT_EQ_H

#endif

int	main(void)
{
	char **chessboard;
	int		position;

	chessboard = init_chessboard();
	position = 0;
	printf("There are %d distinct solutions\n",	back_tracking(chessboard, position));
	return (EXIT_SUCCESS);
}

