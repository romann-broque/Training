/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:18:08 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/27 19:12:50 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define EXPECTED_NB_ARG 3
#define NEW_LINE "\n"

static unsigned int	get_min(const unsigned int nb1, const unsigned int nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

static unsigned int	pgcd(const unsigned int nb1, const unsigned int nb2)
{
	unsigned int	pgcd;

	pgcd = get_min(nb1, nb2);
	while (pgcd > 1 && (nb1 % pgcd != 0 || nb2 % pgcd != 0))
		--pgcd;
	return (pgcd);
}

int	main(int ac, char **av)
{
	int	ret_val;

	ret_val = EXIT_FAILURE;
	if (ac == EXPECTED_NB_ARG)
	{
		printf("%d", pgcd(atoi(av[1]), atoi(av[2])));
		ret_val = EXIT_SUCCESS;
	}
	printf(NEW_LINE);
	return (ret_val);
}
