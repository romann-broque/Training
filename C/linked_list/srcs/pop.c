/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:41:46 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/07 00:13:05 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LINKED_LIST_H

#	include "linked_list.h"

#endif

static void	delete(node **prev, const size_t rank)
{
	if (rank == MIN_SIZE)
		destroy_node(prev);
	else if ((rank > 0) && (rank <= get_size(prev)))
		delete(&(*prev)->link, rank - 1);
}

void	pop(node **prev)
{
	if ((*prev != NULL) && ((*prev)->link != NULL))
		delete(prev, MIN_SIZE);
}

void	cut(node **prev)
{
	const size_t	size = get_size(prev);

	if ((*prev != NULL) && (size > MIN_SIZE))
		delete(prev, size);
}

void	delete_data(node **prev, int input_data)
{
	if (*prev != NULL)
	{
		if ((*prev)->data == input_data)
		{
			destroy_node(prev);
			delete_data(prev, input_data);
		}
		else
			delete_data(&(*prev)->link, input_data);
	}
}
