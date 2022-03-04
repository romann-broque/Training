/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:59:43 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/04 09:21:16 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_element(int data, bin_node *node)
{
	bin_node	*new_node;

	new_node = create_node(data);
	if (data < (*node).data)
	{
		if ((*node).l_link == NULL)
			(*node).l_link = new_node;
		else
			add_element(data, (*node).l_link);
	}
	else if (data > (*node).data)
	{
		if ((*node).r_link == NULL)
			(*node).r_link = new_node;
		else
			add_element(data, (*node).r_link);
	}
}

void	destroy_tree(bin_node **node)
{
	if ((**node).l_link != NULL)
		destroy_tree(&(**node).l_link);
	if ((**node).r_link != NULL)
		destroy_tree(&(**node).r_link);
	free(*node);
	*node = NULL;
}

bin_node *create_node(int numb)
{
	bin_node *current;

	current = (bin_node *)malloc(sizeof(bin_node));
	if (current != NULL)
	{
		current -> data = numb;
		current -> l_link = NULL;
		current -> r_link = NULL;
	}
	return (current);
}

bin_node	*create_tree(int node_number, char **node_data)
{
	bin_node	*root;
	int			i;

	i = 1;
	root = NULL;
	if (node_number > 1)
	{
		root = create_node(atoi(node_data[i]));
		++i;
		while (i <= node_number)
		{
			add_element(atoi(node_data[i]), root);
			++i;
		}
	}
	return (root);
}
