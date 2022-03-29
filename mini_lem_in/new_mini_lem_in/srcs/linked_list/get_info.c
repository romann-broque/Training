/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:41:16 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/25 12:21:08 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

size_t	get_size(t_list **prev)
{
	if (*prev != NULL)
		return (1 + get_size(&(*prev) -> next));
	return (0);
}

bool	is_in_list(t_list *curr, void *name)
{
	if (curr != NULL)
	{
		if (curr->data == name)
			return (true);
		return (is_in_list(curr->next, name));
	}
	return (false);
}
