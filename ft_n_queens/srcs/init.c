/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:19:33 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 23:12:44 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_n_queens.h"

static void	empty_str(char *str)
{
	size_t	i;

	i = 0;
	while (i < SIZE)
	{
		str[i] = EMPTY;
		++i;
	}
	str[i] = '\0';
}

static void	desalloc(char **chessboard)
{
	size_t	i;

	i = 0;
	while (chessboard != NULL)
	{
		free(chessboard[i]);
		++i;
	}
	free(chessboard);
}

char	**init_chessboard(void)
{
	char	**chessboard;
	size_t	i;

	chessboard = (char **)malloc(SIZE * sizeof(char *));
	if (chessboard != NULL)
	{
		i = 0;
		while (i < SIZE)
		{
			chessboard[i] = (char *)malloc((SIZE + 1) * sizeof(char));
			if (chessboard[i] != NULL)
				empty_str(chessboard[i]);
			else
			{
				desalloc(chessboard);
				break;
			}
			++i;
		}
	}
	return (chessboard);
}
