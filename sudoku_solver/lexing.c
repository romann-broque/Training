/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:59:50 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/16 22:25:19 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	is_correct_char(const char c)
{
	return ((c < '1') && (c > '9') && (c != UNKNOWN));
}

bool	are_correct_char(const char **grid)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len(grid) == SIZE_GRID)
	{
		while (i < SIZE_GRID)
		{
			if (str_len(grid[i]) != SIZE_GRID)
				break;
			while (j < SIZE_GRID)
			{
				if (is_correct_char(grid[i][j]))
					break;
				++j;
			}
			++i;
		}
		return (true);
	}
	return (false);
}

//bool	is_still_unknown(char **grid)
