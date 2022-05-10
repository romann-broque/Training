/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:16:37 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/06 10:04:14 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static size_t	is_neg(const int nb)
{
	return (nb < 0);
}

static int	pow(const int nb, const int p)
{
	if (p == 0)
		return (1);
	else if (p < 0)
		return (0);
	return (nb * pow(nb, p - 1));
}

static size_t	get_n_size(const int nb)
{
	size_t	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb / (pow(10, size)) != 0)
		++size;
	return (size);
}

static void	fill_str(char *nb_str, size_t size, int nb)
{
	size_t	i;
	int		digit;

	i = 0;
	while (i < size)
	{
		digit = nb / pow(10, size - 1 - i);
		nb -= digit * pow (10, size - 1 - i);
		nb_str[i] = '0' + digit;
		++i;
	}
	nb_str[size] = '\0';
}

static int	get_abs(const int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

char	*itoa(const int nb)
{
	const size_t	size = get_n_size(nb);
	const size_t	negativity = is_neg(nb);
	char			*expr;

	expr = (char *) malloc((size + negativity + 1) * sizeof(char));
	if (expr != NULL)
	{
		if (negativity)
			expr[0] = '-';
		fill_str(expr + negativity, size, get_abs(nb));
	}
	return (expr);
}
