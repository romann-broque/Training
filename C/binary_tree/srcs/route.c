/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:57:02 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/06 19:27:03 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H

#	define BINARY_TREE_H
#	include "binary_tree.h"

#endif

void	prefix_route(bin_node *parent)
{
	printf("%d\n", parent->data);
	if (parent->left != NULL)
		prefix_route(parent->left);
	if (parent->right != NULL)
		prefix_route(parent->right);
}

void	postfix_route(bin_node *parent)
{
	if (parent->left != NULL)
		postfix_route(parent->left);
	if (parent->right != NULL)
		postfix_route(parent->right);
	printf("%d\n", parent->data);
}

void	infix_route(bin_node *parent)
{
	if (parent->left != NULL)
		infix_route(parent->left);
	printf("%d\n", parent->data);
	if (parent->right != NULL)
		infix_route(parent->right);
}

void	width_route(bin_node *parent)
{
	int	floor;
	int	depth;

	floor = 1;
	depth = get_depth(parent);
	while (floor <= depth)
	{
		display_floor(parent, floor);
		++floor;
	}
}

void	depth_route(bin_node *parent)
{
	int	floor;

	floor = get_depth(parent);
	while (floor > 0)
	{
		display_floor(parent, floor);
		--floor;
	}
}
