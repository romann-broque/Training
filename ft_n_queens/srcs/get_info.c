/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:02:46 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 23:12:27 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_n_queens.h"	

size_t	str_len(char *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0')
		++size;
	return (size);
}

bool	is_queen(char *str)
{
	size_t	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			if (str[i] == QUEEN)
				return (true);
			++i;
		}
	}
	return (false);
}

bool	is_in_chessboard(int pos)
{
	return ((pos >= 0) && (pos < SIZE * SIZE));
}

char	read_case(char **chessboard, int position)
{
	int	lign;
	int	column;

	lign = get_lign(position);
	column = get_column(position);

	return(chessboard[lign][column]);
}
