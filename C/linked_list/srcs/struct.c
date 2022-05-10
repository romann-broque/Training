/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:42:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/07 10:24:26 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LINKED_LIST_H

#	include "linked_list.h"

#endif

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

void	destroy_node(node **prev)
{
	node	*temp;

	temp = *prev;
	*prev = (*prev) -> link;
	free(temp);
}

void	destroy_list(node **prev)
{
	if (*prev != NULL)
	{
		if ((*prev)->link != NULL)
			destroy_list(&(*prev)->link);
		free(*prev);
	}
}
