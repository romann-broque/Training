/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:52:14 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/30 16:58:19 by romannbroque     ###   ########.fr       */
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
