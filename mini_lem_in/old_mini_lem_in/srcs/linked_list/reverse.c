/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:42:14 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/24 11:42:32 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

static void	reverse(t_list **root, t_list *address)
{
	if ((*root)->next != NULL)
		reverse(&(*root)->next, *root);
	(*root)->next = address;
}

void	reverse_list(t_list **root)
{
	t_list	*last;

	if (*root != NULL)
	{
		last = *root;
		while (last->next != NULL)
			last = last->next;
		reverse(root, NULL);
		*root = last;
	}	
}
