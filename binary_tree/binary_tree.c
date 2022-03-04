/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:17:17 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/04 10:39:10 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	binary_tree(int route_type, int node_number, char **data)
{
	bin_node *tree;

	if (route_type < NUMB_OF_ROUTE_ALGO)
	{
		tree = create_tree(node_number, data);
		display_route(route_type, tree);
		destroy_tree(&tree);
	}
	else
		printf("INVALID ROUTE\n");
}

int	main(int ac, char **av)
{
	binary_tree(0, ac - 1, av);
	binary_tree(1, ac - 1, av);
	binary_tree(2, ac - 1, av);
	binary_tree(3, ac - 1, av);
	binary_tree(4, ac - 1, av);
	return (EXIT_SUCCESS);
}
