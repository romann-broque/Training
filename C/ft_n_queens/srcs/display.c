/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:21:47 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 23:11:49 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_n_queens.h"

void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

void	ft_putstr(char *str)
{
	const size_t	size = str_len(str);
	write(STDOUT_FILENO, str, (size + 1) * sizeof(char));
}

void	display_chessboard(char **chessboard)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			ft_putchar(chessboard[i][j]);
			ft_putchar(' ');
			++j;
		}
		ft_putchar('\n');
		++i;
	}
	ft_putchar('\n');
}
