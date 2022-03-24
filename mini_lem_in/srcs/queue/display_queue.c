/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:23:18 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/23 18:21:46 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	display_queue(t_queue *queue)
{
	t_node	*temp;

	temp = queue->front;
	while (temp != NULL)
	{
		printf("%s%p", SEPARATOR, temp->name);
		temp = temp->link;
	}
	printf("%s\n", SEPARATOR);
}
