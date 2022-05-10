/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:08:25 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/06 19:28:14 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H

#	define BINARY_TREE_H
#	include "binary_tree.h"

#endif

void	display_floor(bin_node *parent, int floor)
{
	if (parent != NULL)
	{
		if (floor == 1)
			printf("%d\n", parent->data);
		else if (floor > 1)
		{
			display_floor(parent->left, floor - 1);
			display_floor(parent->right, floor - 1);
		}
	}
}

int	get_max(const int a, const int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_depth(bin_node *parent)
{
	int	left_depth;
	int	right_depth;

	left_depth = 0;
	right_depth = 0;
	if (parent != NULL)
	{
		if (parent->left != NULL)
			left_depth = 1 + get_depth(parent->left);
		if (parent->right != NULL)
			right_depth = 1 + get_depth(parent->right);
		if ((left_depth == 0) && (right_depth == 0))
			return (1);
	}
	return get_max(left_depth, right_depth);
}
