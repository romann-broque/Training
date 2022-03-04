/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:57:02 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/03 21:37:23 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	prefix_route(bin_node *node)
{
	printf("%d\n", (*node).data);
	if ((*node).l_link != NULL)
		prefix_route((*node).l_link);
	if ((*node).r_link != NULL)
		prefix_route((*node).r_link);
}

void	postfix_route(bin_node *node)
{
	if ((*node).l_link != NULL)
		postfix_route((*node).l_link);
	if ((*node).r_link != NULL)
		postfix_route((*node).r_link);
	printf("%d\n", (*node).data);
}

void	infix_route(bin_node *node)
{
	if ((*node).l_link != NULL)
		infix_route((*node).l_link);
	printf("%d\n", (*node).data);
	if ((*node).r_link != NULL)
		infix_route((*node).r_link);
}

void	width_route(bin_node *node)
{
	int	floor;
	int	depth;

	floor = 1;
	depth = get_depth(node);
	while (floor <= depth)
	{
		display_floor(node, floor);
		++floor;
	}
}

void	depth_route(bin_node *node)
{
	int	floor;

	floor = get_depth(node);
	while (floor >= 1)
	{
		display_floor(node, floor);
		--floor;
	}
}
