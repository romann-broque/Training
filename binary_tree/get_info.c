/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:08:25 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/03 16:09:13 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_floor(bin_node *node, int floor)
{
	if (node != NULL)
	{
		if (floor == 1)
			printf("%d\n", (*node).data);
		else if (floor > 1)
		{
			display_floor((*node).l_link, floor - 1);
			display_floor((*node).r_link, floor - 1);
		}
	}
}

int	get_max(const int a, const int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_depth(bin_node *node)
{
	int	l_depth;
	int	r_depth;

	l_depth = 0;
	r_depth = 0;
	if ((*node).l_link != NULL)
		l_depth = 1 + get_depth((*node).l_link);
	if ((*node).r_link != NULL)
		r_depth = 1 + get_depth((*node).r_link);
	if ((l_depth == 0) && (r_depth == 0))
		return (1);
	return get_max(l_depth, r_depth);
}
