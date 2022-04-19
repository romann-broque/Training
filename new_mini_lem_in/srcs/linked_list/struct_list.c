/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 00:22:34 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/19 11:41:04 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_list	*create_list(const char *name, void *link)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->data = ft_strdup(name);
		new->next = link;
	}
	return (new);
}

void	add(t_list **parent, t_list *child)
{
	if (*parent == NULL)
		*parent = child;
	else
		(*parent)->next = child;
}

void	destroy(void *node, void destroy_fct(void *))
{
	destroy_fct(node);
}

void	destroy_list(t_list *list, void destroy_fct(void *))
{
	if (list != NULL)
		destroy_list(list->next, destroy_fct);
	destroy_fct(list);
}

void	destroy_node(t_list *node)
{
	destroy(node->data, free);
	destroy(node->next, free);
	destroy(node, free);
}
