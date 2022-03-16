/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:54:42 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/16 17:37:21 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

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
