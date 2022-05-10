/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:16:46 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 18:41:37 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_list	*create_list(void *data, void *link)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->data = data;
		new->next = link;
	}
	return (new);
}

void	add(t_list **parent, t_list *child)
{
	if (*parent == NULL)
		*parent = child;
	else
		add(&(*parent)->next, child);
}

void	add_element(t_list **list, void *element)
{
	t_list	*new_node;

	new_node = create_list(element, NULL);
	add(list, new_node);
}
