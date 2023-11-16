/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:24:57 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/23 15:38:17 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static size_t	get_rank_of_char(const char *const str, const char c)
{
	size_t	rank;

	rank = 0;
	while (str[rank] != '\0') // && str[rank] != c)
	{
		if (str[rank] == c) // virer
			break ; // virer
		++rank;
	}
	return (rank);
}

static int	do_op(const int nb1, const char op, const int nb2)
{
	static int	(*operations[])(const int, const int) = {add, sub,
		mult, division, mod};
	size_t		operator_rank;

	operator_rank = get_rank_of_char(OPERATORS, op);
	return (operations[operator_rank](nb1, nb2));
}

int	main(int ac, char **av)
{
	if (ac == 4) //define
		printf("%d", do_op(atoi(av[1]), av[2][0], atoi(av[3])));
	printf(NEW_LINE);
	return (EXIT_SUCCESS);
}
