/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:41:46 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/24 16:05:17 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static void	delete(t_list **prev, const size_t rank)
{
	if (rank == MIN_SIZE)
		destroy_node(prev);
	else if ((rank > 0) && (rank <= get_size(prev)))
		delete(&(*prev)->next, rank - 1);
}

void	pop(t_list **prev)
{
	if ((*prev != NULL) && ((*prev)->next != NULL))
		delete(prev, MIN_SIZE);
}

void	cut(t_list **prev)
{
	const size_t	size = get_size(prev);

	if ((*prev != NULL) && (size > MIN_SIZE))
		delete(prev, size);
}

void	delete_data(t_list **prev, void *input_data)
{
	if (*prev != NULL)
	{
		if ((*prev)->data == input_data)
		{
			destroy_node(prev);
			delete_data(prev, input_data);
		}
		else
			delete_data(&(*prev)->next, input_data);
	}
}
