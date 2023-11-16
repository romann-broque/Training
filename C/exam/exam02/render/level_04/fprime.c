/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:18:36 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/17 18:01:08 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

unsigned int	ft_putnbr(unsigned int nb)
{
	unsigned int	digit;

	if (nb == 0)
		return (0);
	digit = nb - ft_putnbr(nb / 10) * 10;
	ft_putchar('0' + digit);
	return (nb);
}

bool	is_prime(const unsigned int nb)
{
	unsigned int	sub;

	sub = nb / 2;
	while (sub > 1)
	{
		if (nb % sub == 0)
			return (false);
		--sub;
	}
	return (true);
}

void	fprime(unsigned int nb)
{
	unsigned int	factor;

	if (nb == 0)
		ft_putchar('0');
	else if (nb == 1)
		ft_putchar('1');
	else
	{
		factor = 2;
		while (nb > 1)
		{
			if (nb % factor == 0)
			{
				nb /= factor;
				if (is_prime(factor) == true)
					ft_putnbr(factor);
				if (nb != 1)
					ft_putchar('*');
			}
			else
				++factor;
		}
	}
}

int	main(int ac, char **av)
{
	unsigned int	nb;

	if (ac == 2)
	{
		nb = atoi(av[1]);
		if (nb == 0)
			ft_putchar('0');
		else if (nb > 0)
			fprime(nb);
	}
	ft_putchar('\n');
	return (EXIT_SUCCESS);
}
