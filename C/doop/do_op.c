/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:42:24 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/25 12:03:16 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static size_t	get_rank(char *str, char c)
{
	size_t	i;

	i = 0;
	while (i < NUMB_OF_OP)
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	invalid_operator_error();
	return (i);
}

static long	get_result(int n1, char op, int n2)
{
	const size_t		rank = get_rank(OPERATORS, op);
	long				(*operation[])(long, long) =
	{add, sub, mult, division, mod};

	return ((operation[rank])(n1, n2));
}

void	do_op(char *chn1, char *op, char *chn2)
{
	int		n1;
	int		n2;

	if ((chn1 != NULL) && (chn2 != NULL) && (op != NULL))
	{
		if (str_len(op) == 1)
		{
			if ((is_valid_number(chn1)) && (is_valid_number(chn2)))
			{
				n1 = get_n_from_str(chn1);
				n2 = get_n_from_str(chn2);
				display_result(n1, *op, n2, get_result(n1, *op, n2));
			}
			else
				invalid_numb_error();
		}
		else
			invalid_operator_error();
	}
	else
		null_arg_error();
}

int	main(int ac, char **av)
{
	if (ac > 3)
		do_op(av[1], av[2], av[3]);
	return (EXIT_SUCCESS);
}
