/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:17:17 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/04 09:27:59 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	bin_node *tree;

	tree = create_tree(ac - 1, av);
	display_route(tree);
	destroy_tree(&tree);
	return (EXIT_SUCCESS);
}
