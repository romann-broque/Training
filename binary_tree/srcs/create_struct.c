/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:59:43 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/06 19:29:16 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H

#	define BINARY_TREE_H
#	include "binary_tree.h"

#endif

void	add_element(int new_data, bin_node *parent)
{
	bin_node	*new;

	new = create_node(new_data);
	if (new->data < parent->data)
	{
		if (parent->left == NULL)
			parent->left = new;
		else
			add_element(new_data, parent->left);
	}
	else if (new->data > parent->data)
	{
		if (parent->right == NULL)
			parent->right = new;
		else
			add_element(new_data, parent->right);
	}
}

void	destroy_tree(bin_node **parent)
{
	if ((*parent)->left != NULL)
		destroy_tree(&(*parent)->left);
	if ((*parent)->right != NULL)
		destroy_tree(&(*parent)->right);
	free(*parent);
	*parent = NULL;
}

bin_node *create_node(int nb)
{
	bin_node *new;

	new = (bin_node *)malloc(sizeof(bin_node));
	if (new != NULL)
	{
		new->data = nb;
		new->left = NULL;
		new->right = NULL;
	}
	return (new);
}

bin_node	*create_tree(int node_number, char **node_data)
{
	bin_node	*root;
	int			i;

	i = 0;
	root = NULL;
	if (node_number >= 1)
	{
		root = create_node(atoi(node_data[i]));
		++i;
		while (i < node_number)
		{
			add_element(atoi(node_data[i]), root);
			++i;
		}
	}
	return (root);
}
