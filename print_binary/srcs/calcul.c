/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:42:22 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/11 14:21:24 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_binary.h"

///CALCUL

long	get_abs(const int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

///OUTPUT MANAGEMENT

void	translate_to_bin(char bin_expr[SIZE + 1], const int nb)
{
	const int	nb_cp = get_abs(nb);
	int			rank;
	int			p_two;

	rank = 0;
	p_two = 1;
	while (rank < SIZE - 1)
	{
		if (nb_cp & p_two)
			bin_expr[SIZE - 1 - rank] = '1';
		else
			bin_expr[SIZE - 1 - rank] = '0';
		p_two *= 2;
		++rank;
	}
}
