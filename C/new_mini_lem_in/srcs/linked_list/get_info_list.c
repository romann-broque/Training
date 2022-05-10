/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:52:14 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 16:57:38 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

size_t	get_size_list(t_list *list)
{
	size_t	size;
	t_list	*node;

	size = 0;
	node = list;
	while (node != NULL)
	{
		node = node->next;
		++size;
	}
	return (size);
}

bool	are_lists_equal(t_list *list1, t_list *list2)
{
	if (list1 == NULL || list2 == NULL)
		return (list1 == NULL && list2 == NULL);
	if (list1->data == list2->data)
		return (are_lists_equal(list1->next, list2->next));
	return (false);
}
