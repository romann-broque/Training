/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:23:25 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/03 19:00:20 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	display_room(t_room *head)
{
	printf("%s : ", (char *)head->name);
	display_list_room(head->neighboor);
}

void	display_list_room(t_list *prev)
{
	t_room	*next;

	if (prev != NULL && prev->data != NULL)
	{
		next = prev->data;
		printf("%s%s", SEPARATOR, (char *)next->name);
		if (prev->next != NULL)
			display_list_room(prev->next);
		else
			printf("%s\n", SEPARATOR);
	}
	else
		printf("\n");
}
