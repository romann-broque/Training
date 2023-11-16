/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:07:11 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/27 18:52:15 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "rpn_calc.h"

#define EXPECTED_NB_ARGS 2
#define SPACE ' '
#define FIRST_WHITESPACE 8
#define LAST_WHITESPACE 13
#define WHITESPACE true
#define WORD false

size_t	get_rank(const char *const str, const char c)
{
	size_t	rank;

	rank = 0;
	while (str[rank] != '\0' && str[rank] != c)
		++rank;
	return (rank);
}

long	do_op(const int nb1, const int nb2, const char op)
{
	size_t	index;
	long	(*operators[])(const int, const int) = {add, sub, mult, divide, mod};

	index = get_rank(OPERATORS, op);
	return (operators[index](nb1, nb2));
}

size_t	get_nb_size(const char *const str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0' && (str[size] >= 0 && str[size] <= 9))
		++size;
	return (size);
}

bool	is_whitespace(const char c)
{
	return (c == SPACE || (c >= FIRST_WHITESPACE && c <= LAST_WHITESPACE));
}

char	*skip_sequence(const char *str, const bool type)
{
	while (*str != '\0' && is_whitespace(*str) == type)
		++str;
	return ((char *)str);
}

int	rpn_calc(const char *str)
{
	int	nb1;
	int	nb2;
	char op;

	nb1 = atoi(str);
	str = skip_sequence(str, WORD);
	str = skip_sequence(str, WHITESPACE);
	nb2 = atoi(str);
	str = skip_sequence(str, WORD);
	str = skip_sequence(str, WHITESPACE);
	op = str[0];
	return (do_op(nb1, nb2, op));
}

int	main(int ac, char **av)
{
	int	ret_val;

	ret_val = EXIT_FAILURE;
	if (ac == EXPECTED_NB_ARGS)
	{
		printf("%d\n", rpn_calc(av[1]));
		ret_val = EXIT_SUCCESS;
	}
	return (ret_val);
}
