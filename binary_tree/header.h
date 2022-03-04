/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:00:33 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/04 09:27:36 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef	struct node
{
	int			data;
	struct node	*l_link;
	struct node	*r_link;
} bin_node;

//create_struct.c//

void		add_element(int data, bin_node *node);
void		destroy_tree(bin_node **node);
bin_node	*create_node(int data);
bin_node	*create_tree(int node_number, char **node_data);

//route.c//

void	prefix_route(bin_node *node);
void	postfix_route(bin_node *node);
void	infix_route(bin_node *node);
void	width_route(bin_node *node);
void	depth_route(bin_node *node);

//get_info.c//

void	display_floor(bin_node *node, int floor);
int		get_max(int a, int b);
int		get_depth(bin_node *node);

//display.c//

void	display_route(bin_node *node);
