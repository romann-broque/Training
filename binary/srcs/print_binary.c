/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:46:39 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 15:57:11 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary.h"

void	print_binary(const int nb)
{
	char	bin_expr[NUMB_OF_BITS + 1];
	int		rank;
	int		i;

	rank = 0;
	i = 1;
	while (rank < NUMB_OF_BITS)
	{
		if (nb & i)
			bin_expr[NUMB_OF_BITS - rank - 1] = '1';
		else
			bin_expr[NUMB_OF_BITS - rank - 1] = '0';
		i <<= 1;
		++rank;
	}
	bin_expr[NUMB_OF_BITS] = '\0';
	display_bin(bin_expr);
}
