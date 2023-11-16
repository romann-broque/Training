/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:41:29 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/27 15:16:25 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	size_t			i;
	unsigned char	bit;
	unsigned char	rev;

	i = 0;
	rev = 0;
	while (i < 8 * sizeof(char))
	{
		bit = ((octet >> i) & 0x01);
		rev |= (bit <<  (7 - i));
		++i;
	}
	return (rev);
}

int	main(void)
{
	printf("%d\n", reverse_bits(42));
	return (0);
}
