/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:41:16 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/24 17:14:13 by romannbroque     ###   ########.fr       */
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
	if (curr != NULL && curr->data != NULL)
	{
		if (curr->data == name)
			return (true);
		return (is_in_list(curr->next, name));
	}
	return (false);
}
