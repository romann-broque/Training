/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:16:46 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/27 10:11:31 by romannbroque     ###   ########.fr       */
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
