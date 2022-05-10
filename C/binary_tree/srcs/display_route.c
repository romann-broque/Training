/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_route.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:21:36 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/06 19:07:55 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H

#	define BINARY_TREE_H
#	include "binary_tree.h"

#endif

void	display_route(int route_type, bin_node *tree)
{
	const char	*route_name[] =
								{"Prefix",
								"Postfix",
								"Infix",
								"Width",
								"Depth"};
	void	(*route_algo[NUMB_OF_ROUTE_ALGO])(bin_node *) =
															{prefix_route,
															postfix_route,
															infix_route,
															width_route,
															depth_route};

	printf("%s route :\n", route_name[route_type]);
	route_algo[route_type](tree);
}
