/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:02:46 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/08 17:03:48 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_EQ_H

#	include "ft_eight_queens.h"	
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

int	is_count_queens(char **chessboard)
{
	int		count;
	size_t	i;
	size_t	j;

	count = 0;
	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (chessboard[i][j] == QUEEN)
				++count;
			++j;
		}
		++i;
	}
	return (count);
}
