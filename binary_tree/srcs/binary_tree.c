/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:17:17 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/06 19:31:16 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H

#	define BINARY_TREE_H
#	include "binary_tree.h"

#endif

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		bin_node *tree = create_tree(ac - 1, av + 1);
		display_route(E_PREFIX, tree);
		display_route(E_POSTFIX, tree);
		display_route(E_INFIX, tree);
		display_route(E_WIDTH, tree);
		display_route(E_DEPTH, tree);
		destroy_tree(&tree);
	}
	return (EXIT_SUCCESS);
}
