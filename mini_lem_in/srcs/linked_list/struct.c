/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:42:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/01 23:47:42 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*create_list(void *input_data)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->data = input_data;
		new->next = NULL;
	}
	return (new);
}

void	destroy_node(t_list **prev)
{
	t_list	*temp;

	temp = *prev;
	*prev = (*prev)->next;
	free(temp);
}

void	destroy_list(t_list **prev)
{
	if (*prev != NULL)
	{
		if ((*prev)->next != NULL)
			destroy_list(&(*prev)->next);
		*prev = NULL;
		free(*prev);
	}
}
