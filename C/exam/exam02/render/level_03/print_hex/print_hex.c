/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:00:38 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/17 16:10:34 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define HEXA "0123456789abcdef"

static size_t	ft_strlen(const char *const str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

static void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

static  bool	is_nb(const char *const str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		++i;
	}
	return (*str != '\0');
}

static unsigned long	get_nb_from_str(const char *const str)
{
	const size_t	size = ft_strlen(str);
	ssize_t			i;
	unsigned long	nb;
	unsigned long	decade;

	nb = 0;
	if (is_nb(str) == true)
	{
		i = size - 1;
		decade = 1;
		while (i >= 0)
		{
			nb += (str[i] - '0') * decade;
			decade *= 10;
			--i;
		}
	}
	return (nb);
}

static unsigned long	print_hex(const unsigned long nb, unsigned long decade)
{
	unsigned long	digit;

	if (decade == 0)
		return (0);
	if (nb != 0)
	{
		digit = nb - print_hex(nb / 16, decade - 1) * 16;
		ft_putchar(HEXA[digit]);
	}
	return (nb);
}

int	main(int ac, char **av)
{
	unsigned long	nb;

	if (ac == 2)
	{
		nb = get_nb_from_str(av[1]);
		if (nb == 0)
			ft_putchar(HEXA[0]);
		else
			print_hex(nb, ft_strlen(av[1]));
		ft_putchar('\n');
	}
	return (EXIT_SUCCESS);
}
