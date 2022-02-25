/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:53 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/25 10:40:10 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(c));
}

void	ft_putstr(const char *str)
{
	if (str != NULL)
		write(STDOUT_FILENO, str, (str_len(str) + 1) * sizeof(char));
}

void	ft_put_longnbr(long nbr)
{
	int		nbr_size;
	int		digit;
	long	pow;

	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	nbr_size = get_n_size(nbr);
	pow = power(10, nbr_size - 1);
	digit = nbr / pow;
	ft_putchar('0' + digit);
	if (nbr_size > 1)
		ft_put_longnbr(nbr - digit * pow);
}

void	display_result(int n1, char op, int n2, long result)
{
	ft_put_longnbr(n1);
	ft_putchar(' ');
	ft_putchar(op);
	ft_putchar(' ');
	if (n2 < 0)
	{
		ft_putchar('(');
		ft_put_longnbr(n2);
		ft_putchar(')');
	}
	else
		ft_put_longnbr(n2);
	ft_putstr(" = ");
	ft_put_longnbr(result);
	ft_putchar('\n');
}
