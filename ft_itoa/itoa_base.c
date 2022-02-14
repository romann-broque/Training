/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:13:51 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/14 17:28:00 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

static size_t	str_len(const char *str)
{
	size_t	len;

	len = 0;
	if (str != NULL)
	{
		while (str[len] != '\0')
			++len;
	}
	return (len);
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
	while (nb / pow(len_base, size) != 0)
		++size;
	return (size);
}

static char	*get_coord(int nb, const char *base_charset, size_t size)
{
	const size_t	len_base = str_len(base_charset);
	size_t			i;
	int				unit;
	int				div;
	char			*tr_expr;

	i = size;
	tr_expr = (char *) malloc((size + 1) * sizeof(char));
	while (i > 0)
	{
		div = pow(len_base, i - 1);
		unit = nb / div;
		tr_expr[size - i] = base_charset[unit];
		nb -= unit * div;
		--i;
	}
	tr_expr[size] = '\0';
	return (tr_expr);
}

static char	*itoa_base(const int nb, const char *base_charset)
{
	const size_t	len = str_len(base_charset);
	size_t			size;
	char			*expr;

	if ((is_double(base_charset) == false) && (len > 1))
	{
		size = get_size(nb, len);
		expr = get_coord(nb, base_charset, size);
		return (expr);
	}
	return (NULL);
}
