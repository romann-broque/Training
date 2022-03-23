/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:23:25 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/22 18:06:18 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	display_room(t_room *head)
{
	printf("%s(%p) : ", (char *)head->id, head);
	display_list(head->link);
	printf("\n");
}

void	display_list_room(t_node *prev)
{
	t_room	*next;

	if (prev != NULL)
	{
		next = prev->name;
		printf("%s%s", SEPARATOR, (char *)next->id);
		if (prev->link != NULL)
			display_list_room(prev->link);
		else
			printf("%s", SEPARATOR);
	}
}
