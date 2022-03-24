/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:42:00 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/24 16:19:17 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	add(t_list *prev, void *input_data)
{
	t_list	*new_node;

	if (prev != NULL)
	{
		if (prev->next != NULL)
			add(prev->next, input_data);
		else
		{
			new_node = create_list(input_data);
			prev->next = new_node;
		}
	}
}

void	insert(t_list **prev, void *input_data, size_t rank)
{
	t_list	*new;
	t_list	*temp;

	if (*prev != NULL)
	{
		new = create_list(input_data);
		if (rank == MIN_SIZE)
		{
			new->next = *prev;
			*prev = new;
		}
		else if (rank == MIN_SIZE + 1)
		{
			temp = new;
			new->next = (*prev)->next;
			(*prev)->next = temp;
		}
		else
			insert(&(*prev)->next, input_data, rank - 1);
	}
}

void	push(t_list **prev, void *input_data)
{
	if (*prev != NULL)
		insert(prev, input_data, 1);
}
