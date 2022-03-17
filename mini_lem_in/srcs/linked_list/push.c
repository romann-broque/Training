/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:42:00 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/17 23:46:40 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	add(t_node *prev, char *input_data)
{
	t_node	*new_node;

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

void	insert(t_node **prev, char *input_data, size_t rank)
{
	t_node	*new;
	t_node	*temp;

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

void	push(t_node **prev, char *input_data)
{
	if (*prev != NULL)
		insert(prev, input_data, 1);
}
