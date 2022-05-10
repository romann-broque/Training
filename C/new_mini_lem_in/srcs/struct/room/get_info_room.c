/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:32:37 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 12:46:47 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_room	*find_room(t_list *list, const char *name)
{
	if (list != NULL && list->data != NULL)
	{
		if (ft_is_equal(((t_room *)(list->data))->name, name))
			return (list->data);
		return (find_room(list->next, name));
	}
	return (NULL);
}
