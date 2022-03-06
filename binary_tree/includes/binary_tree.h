/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:00:33 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/06 16:47:59 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMB_OF_ROUTE_ALGO 5

enum e_travel
{
	E_PREFIX,
	E_POSTFIX,
	E_INFIX,
	E_WIDTH,
	E_DEPTH,
};

typedef	struct	node
{
	int			data;
	struct node	*left;
	struct node	*right;
} 				bin_node;

//create_struct.c//

void		add_element(int data, bin_node *parent);
void		destroy_tree(bin_node **tree);
bin_node	*create_node(int data);
bin_node	*create_tree(int node_number, char **node_data);

//route.c//

void	prefix_route(bin_node *parent);
void	postfix_route(bin_node *parent);
void	infix_route(bin_node *parent);
void	width_route(bin_node *parent);
void	depth_route(bin_node *parent);

//get_info.c//

void	display_floor(bin_node *parent, int floor);
int		get_max(int a, int b);
int		get_depth(bin_node *parent);

//display.c//

void	display_route(int route_type, bin_node *parent);
