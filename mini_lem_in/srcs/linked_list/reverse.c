/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:42:14 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/17 23:24:28 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

static void	reverse(t_node **root, t_node *address)
{
	if ((*root)->link != NULL)
		reverse(&(*root)->link, *root);
	(*root)->link = address;
}

void	reverse_list(t_node **root)
{
	t_node	*last;

	if (*root != NULL)
	{
		last = *root;
		while (last->link != NULL)
			last = last->link;
		reverse(root, NULL);
		*root = last;
	}	
}
