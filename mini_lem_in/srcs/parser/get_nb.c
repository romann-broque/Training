/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:05:04 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/16 17:25:06 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

static long		power(int nb, int p)
{
	if (p <= 0)
		return (1);
	return (nb * power(nb, p - 1));
}

unsigned int	get_nb_size_from_str(char *number, char end_char)
{
	unsigned int	size;

	size = 0;
	while (number[size] != '\0' && number[size] != end_char)
		++size;
	return (size);
}

static unsigned int	get_nb(const char *str, int size, int sign)
{
	long	nb;
	int		i;

	nb = 0;
	i = 0;
	while (i < size)
	{
		nb += power(10, size - i - 1) * (str[i] - '0');
		++i;
	}
	nb *= sign;
	return (nb);
}

unsigned int	get_nb_size(long nb)
{
	unsigned int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		++size;
	}
	return (size);
}

int		get_nb_from_str(char *str, char end_char)
{
	int	i;
	int sign;
	int	size;

	i = 0;
	sign = 1;
	if (str[i] == '-')
	{	
		sign = -1;
		++i;
	}
	size = get_nb_size_from_str(str + i, end_char);
	return (get_nb(str + i, size, sign));
}
