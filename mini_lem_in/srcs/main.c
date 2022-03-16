/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:49:58 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/16 17:59:09 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	main(int ac, char **av)
{
	int	nb1;
	int	nb2;

	if (ac > 1)
	{
		if (is_start_inst(av[1]))
		{
			nb1 = get_nb_from_str(av[1] + str_len(START_PATTERN), '\0');
			start(nb1);
		}
		if (is_end_inst(av[1]))
		{
			nb1 = get_nb_from_str(av[1] + str_len(END_PATTERN), '\0');
			end(nb1);
		}
		if (is_link_inst(av[1]))
		{
			nb1 = get_nb_from_str(av[1], DELIM);
			nb2 = get_nb_from_str(av[1] + get_nb_size(nb1) + 1, '\0');
			link_nodes(nb1, nb2);
		}
	}
	return (EXIT_SUCCESS);
}
