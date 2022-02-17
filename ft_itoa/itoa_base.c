/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:13:51 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/17 18:34:23 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FORBIDDEN_CHAR "+-"

static size_t	str_len(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

static int	get_abs(const int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static	bool	is_forbidden_char(const char *base_charset)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (base_charset[i] != '\0')
	{
		j = 0;
		while (FORBIDDEN_CHAR[j] != '\0')
		{
			if (base_charset[i] == FORBIDDEN_CHAR[j])
				return (true);
			++j;
		}
		++i;
	}
	return (false);
}

static int	pow(const int nb, const size_t p)
{
	if (p == 0)
		return (1);
	return (nb * pow(nb, p - 1));
}

static bool	is_double(const char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str == NULL)
		return (true);
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (true);
			++j;
		}
		++i;
	}
	return (false);
}

static size_t	get_size(const int nb, size_t len_base)
{
	size_t	size;

	size = 0;
	if (nb == 0)
		return(1);
	while (nb / pow(len_base, size) != 0)
		++size;
	return (size);
}

static char	*get_coord(int nb, const char *base_charset,
									size_t size, size_t sign)
{
	const size_t	len_base = str_len(base_charset);
	size_t			i;
	long			unit;
	long			div;
	char			*tr_expr;

	i = size;
	tr_expr = (char *) malloc((size + sign + 1) * sizeof(char));
	if (tr_expr != NULL)
	{
		if (sign == 1)
			tr_expr[0] = '-';
		while (i > sign)
		{
			div = pow(len_base, i - 1);
			unit = nb / div;
			tr_expr[size - i] = base_charset[unit];
			nb -= unit * div;
			--i;
		}
		tr_expr[size + sign] = '\0';
	}
	return (tr_expr);
}

static char	*itoa_base(const int nb, const char *base_charset)
{
	if (base_charset != NULL)
	{
		const size_t	len = str_len(base_charset);
		const size_t	negativity = (nb < 0);
		size_t			size;
		char			*expr;

		if ((is_forbidden_char(base_charset) == false)
			&& (is_double(base_charset) == false)
			&& (len > 1))
		{
			size = get_size(nb, len);
			expr = get_coord(get_abs(nb), base_charset, size, negativity);
			return (expr);
		}
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	if (ac > 2)
		printf("%s\n", itoa_base(atoi(av[1]), av[2]));
	return (EXIT_SUCCESS);
}
