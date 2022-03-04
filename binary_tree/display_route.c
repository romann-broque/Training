/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:21:36 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/04 09:28:29 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_route(bin_node *node)
{
	printf("Prefix route :\n");
	prefix_route(node);
	printf("\nPostroute :\n");
	postfix_route(node);
	printf("\nInfix route :\n");
	infix_route(node);
	printf("\nWidthfix route :\n");
	width_route(node);
	printf("\nDepthfix route :\n");
	depth_route(node);
}
