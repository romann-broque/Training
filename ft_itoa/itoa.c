/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:16:37 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/15 15:35:40 by romannbroque     ###   ########.fr       */
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
	if (nb == 0)
		return (0);
	return (1 + get_n_size(nb / 10));
}

/*
static void	fill_str(char *nb_str, size_t rank, size_t max_rank, int nb)
{
	if (rank == max_rank)
		nb_str[rank] = '\0';
	else
	{
		int	digit;

		digit = nb / 10;
		nb -= digit * 10;
		fill_str(nb_str, rank + 1, max_rank, nb / 10);
		nb_str[rank] = '0' + digit;
	}
}
*/

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

int	main(int ac, char **av)
{
	if (ac > 1)
		printf("%s\n", itoa(atoi(av[1])));
	return (EXIT_SUCCESS);
}
