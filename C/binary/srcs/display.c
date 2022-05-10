/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:20:36 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 15:56:03 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary.h"

static void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

void	display_bin(char bin_expr[NUMB_OF_BITS + 1])
{
	size_t	rank;

	rank = 0;
	while (bin_expr[rank] != '\0')
	{
		if ((rank != 0) && (rank % 8 == 0))
			ft_putchar(' ');
		ft_putchar(bin_expr[rank]);
		++rank;
	}
	ft_putchar('\n');
}
