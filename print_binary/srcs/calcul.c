/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:42:22 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/10 22:28:17 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_binary.h"

///CALCUL

int		get_max_bit(const int nb)
{
	int	nb_cp;
	int	max_bit;

	nb_cp = nb;
	max_bit = 0;
	while (nb_cp != 0)
	{
		nb_cp /= 2;
		++max_bit;
	}
	return (max_bit);
}

long	get_abs(const int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

///OUTPUT MANAGEMENT

void	translate_to_bin(char bin_expr[SIZE + 1], const int nb)
{
	int			bit;
	int			quotient;
	int			rank;
	long		nb_cp;

	rank = 0;
	nb_cp = get_abs(nb);
	while (rank < SIZE - 1)
	{
		if (nb_cp > 0)
		{
			bit = nb_cp % 2;
			quotient = nb_cp / 2;
			bin_expr[SIZE - 1 - rank] = '0' + bit;
			nb_cp = quotient;
		}
		else
			bin_expr[SIZE - 1 - rank] = '0';
		++rank;
	}
}
