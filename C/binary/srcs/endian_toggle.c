/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian_toggle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:36:40 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 15:56:39 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary.h"
#include <stdio.h>

static int	get_nth_byte(const int nb, int n)
{
	int	nb_cp;

	nb_cp = (nb >> (BYTE_SIZE * n)) & 0xff;
	nb_cp <<= -BYTE_SIZE * (n + 1);
	return (nb_cp);
}

int	endian_toggle(const int nb)
{
	const int	byte1 = get_nth_byte(nb, 0);
	const int	byte2 = get_nth_byte(nb, 1);
	const int	byte3 = get_nth_byte(nb, 2);
	const int	byte4 = get_nth_byte(nb, 3);

	return (byte1 | byte2 | byte3 | byte4);
}
