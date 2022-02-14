/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:16:37 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/14 17:27:45 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_sign(const int nb)
{
	if (nb >= 0)
		return (0);
	return (1);
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

static void	attribute(char *nb_str, size_t size, size_t sign, int nb)
{
	size_t	i;
	size_t	true_size;
	int		digit;

	i = 0;
	if (nb < 0)
		nb = -nb;
	true_size = size + sign;
	while (i < true_size)
	{
		digit = nb / pow(10, size - 1 - i);
		nb -= digit * pow (10, size - 1 - i);
		nb_str[i + sign] = '0' + digit;
		++i;
	}
	nb_str[true_size] = '\0';
}

char	*itoa(const int nb)
{
	const size_t	size = get_n_size(nb);
	const size_t	sign = get_sign(nb);
	char			*expr;

	expr = (char *) malloc((size + sign + 1) * sizeof(char));
	if (nb < 0)
		expr[0] = '-';
	attribute(expr, size, sign, nb);
	return (expr);
}
