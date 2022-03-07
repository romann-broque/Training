/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:42:00 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/06 19:42:03 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LINKED_LIST_H

#	include "linked_list.h"

#endif

void	add(node *prev, int input_data)
{
	node	*new_node;

	if (prev != NULL)
	{
		if (prev -> link != NULL)
			add(prev -> link, input_data);
		else
		{
			new_node = create_node(input_data);
			prev -> link = new_node;
		}
	}
}

void	insert(node **prev, int	input_data, size_t rank)
{
	node	*new;
	node	*temp;

	if (*prev != NULL)
	{
		new = create_node(input_data);
		if (rank == MIN_SIZE)
		{
			new -> link = *prev;
			*prev = new;
		}
		else if (rank == MIN_SIZE + 1)
		{
			temp = new;
			new -> link = (*prev) -> link;
			(*prev) -> link = temp;
		}
		else
			insert(&(*prev) -> link, input_data, rank - 1);
	}
}

void	push(node **prev, int input_data)
{
	if (*prev != NULL)
		insert(prev, input_data, 1);
}
