/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:02:46 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/09 17:12:55 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_EQ_H

#	include "ft_n_queens.h"	
#	define	FT_EQ_H

#endif

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
	int		count_q;

	i = 0;
	count_q = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			if (str[i] == QUEEN)
				++count_q;
			if (count_q == 1)
				return (true);
			++i;
		}
	}
	return (false);
}

bool	is_in_chessboard(int pos)
{
	const int	lign = pos / 10;
	const int	column = pos % 10;
	
	return ((lign >= 0) && (lign < SIZE)
			&& (column >= 0) && (column < SIZE));
}

