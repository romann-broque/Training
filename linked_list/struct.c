/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:40:08 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/05 19:38:36 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

node	*create_node(int input_data)
{
	node *new;

	new = (node *)malloc(sizeof(node));
	if (new != NULL)
	{
		new -> data = input_data;
		new -> link = NULL;
	}
	return (new);
}

node	*destroy_node(node **prev)
{
	node	*temp;

	temp = *prev;
	*prev = (*prev) -> link;
//	free(temp);
	return (temp);
}
