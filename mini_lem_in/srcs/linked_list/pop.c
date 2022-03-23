/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:41:46 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/18 11:19:15 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

static void	delete(t_node **prev, const size_t rank)
{
	if (rank == MIN_SIZE)
		destroy_node(prev);
	else if ((rank > 0) && (rank <= get_size(prev)))
		delete(&(*prev)->link, rank - 1);
}

void	pop(t_node **prev)
{
	if ((*prev != NULL) && ((*prev)->link != NULL))
		delete(prev, MIN_SIZE);
}

void	cut(t_node **prev)
{
	const size_t	size = get_size(prev);

	if ((*prev != NULL) && (size > MIN_SIZE))
		delete(prev, size);
}

void	delete_data(t_node **prev, void *input_data)
{
	if (*prev != NULL)
	{
		if ((*prev)->name == input_data)
		{
			destroy_node(prev);
			delete_data(prev, input_data);
		}
		else
			delete_data(&(*prev)->link, input_data);
	}
}
