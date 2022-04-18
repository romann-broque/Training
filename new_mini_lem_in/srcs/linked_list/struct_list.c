/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 00:22:34 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/18 17:21:52 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_list	*create_list(const char *name)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->data = ft_strdup(name);
		new->next = NULL;
	}
	return (new);
}

/*
void	add(t_list *parent, void *child)
{
	parent->next = child;
}
*/
