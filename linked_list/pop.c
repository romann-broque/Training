/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:44:24 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/06 09:28:12 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static node	*delete(node **prev, const size_t rank)
{
	if (rank == MIN_SIZE)
		return (destroy_node(prev));
	else if ((rank > 0) && (rank <= get_size(prev)))
		return (delete(&(*prev) -> link, rank - 1));
	else
		return (NULL);
}

node	*pop(node **prev)
{
	if ((*prev != NULL) && ((*prev) -> link != NULL))
		return (delete(prev, MIN_SIZE));
	return (NULL);
}

node	*cut(node **prev)
{
	const size_t	size = get_size(prev);

	if ((*prev != NULL) && (size > MIN_SIZE))
		return (delete(prev, size));
	return (NULL);
}

void	delete_data(node **prev, int input_data)
{
	if (*prev != NULL)
	{
		if ((*prev) -> data == input_data)
		{
			destroy_node(prev);
			delete_data(prev, input_data);
		}
		else
			delete_data(&(*prev) -> link, input_data);
	}
}
