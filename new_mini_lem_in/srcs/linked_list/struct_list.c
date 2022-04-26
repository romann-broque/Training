/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 00:22:34 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/26 10:03:42 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_list	*create_list(const char *name, void *link)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		if (name == NULL)
			new->data = NULL;
		else
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
		add(&(*parent)->next, child);
}

void	destroy(void *node, void destroy_fct())
{
	destroy_fct(node);
}

void	cut(t_list **head, void (*destroy_fct)())
{
	if (*head != NULL)
	{
		if ((*head)->next != NULL)
			cut(&(*head)->next, destroy_fct);
		else
			destroy_node(head, destroy_fct);
	}
}

void	destroy_node(t_list **node, void (*destroy_fct)())
{
	if (destroy_fct != NULL)
	{
		destroy(&(*node)->data, destroy_fct);
		destroy(&(*node)->next, full_free);
	}
	destroy(node, full_free);
}

void	destroy_list(t_list **head, void destroy_fct())
{
	while (*head != NULL)
		cut(head, destroy_fct);
}
