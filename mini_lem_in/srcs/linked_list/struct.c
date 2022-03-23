/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:42:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/18 11:20:38 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_node	*create_node(void *input_data)
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new != NULL)
	{
		new -> name = input_data;
		new -> link = NULL;
	}
	return (new);
}

void	destroy_node(t_node **prev)
{
	t_node	*temp;

	temp = *prev;
	*prev = (*prev) -> link;
	free(temp);
}

void	destroy_list(t_node **prev)
{
	if (*prev != NULL)
	{
		if ((*prev)->link != NULL)
			destroy_list(&(*prev)->link);
		free(*prev);
	}
}
