/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:42:14 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/07 10:18:15 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LINKED_LIST_H

#	include "linked_list.h"

#endif

static void	reverse(node **root, node *address)
{
	if ((*root)->link != NULL)
		reverse(&(*root)->link, *root);
	(*root)->link = address;
}

void	reverse_list(node **root)
{
	node	*last;

	if (*root != NULL)
	{
		last = *root;
		while (last->link != NULL)
			last = last->link;
		reverse(root, NULL);
		*root = last;
	}	
}
