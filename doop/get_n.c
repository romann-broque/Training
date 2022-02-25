/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:15:17 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/25 12:03:36 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	get_n_size_from_str(char *number)
{
	unsigned int	size;

	size = 0;
	while (is_numb(number[size]))
		++size;
	return (size);
}

static unsigned int	get_n(const char *str, int size, int sign)
{
	long	n;
	int	i;

	n = 0;
	i = 0;
	while (is_numb(str[i]))
	{
		n += power(10, size - i - 1) * (str[i] - '0');
		++i;
	}
	n *= sign;
	if ((n < (long)INT_MIN) || (n > (long)INT_MAX))
		invalid_numb_error();
	return (n);
}

unsigned int	get_n_size(long n)
{
	unsigned int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		++size;
	}
	return (size);
}

int		get_n_from_str(char *str)
{
	int	i;
	int sign;
	int	size;

	i = 0;
	sign = 1;
	while ((str[i] != '-') && (is_numb(str[i]) == false) && (str[i] != '\0'))
		++i;
	if (str[i] == '-')
	{	
		sign = -1;
		++i;
	}
	size = get_n_size_from_str(str + i);
	if (size == 0)
		invalid_numb_error();
	return (get_n(str + i, size, sign));
}
