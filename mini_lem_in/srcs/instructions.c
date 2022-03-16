/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:54:42 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/16 18:18:54 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	inst(char *line)
{
	int	nb1;
	int nb2;

	if (is_start_inst(line))
	{
		nb1 = get_nb_from_str(line + str_len(START_PATTERN), '\0');
		start(nb1);
	}
	else if (is_end_inst(line))
	{
		nb1 = get_nb_from_str(line + str_len(END_PATTERN), '\0');
		end(nb1);
	}
	else if (is_link_inst(line))
	{
		nb1 = get_nb_from_str(line, DELIM);
		nb2 = get_nb_from_str(line + get_nb_size(nb1) + 1, '\0');
		link_nodes(nb1, nb2);
	}
}

void	start(int nb)
{
	printf("Start : %d\n", nb);
}

void	end(int nb)
{
	printf("END : %d\n", nb);
}

void	link_nodes(int nb1, int nb2)
{
	printf("LINK : %d-%d\n", nb1, nb2);
}
