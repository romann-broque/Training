/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:24:25 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/23 18:28:30 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_queue	*init_queue(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (queue != NULL)
	{
		queue->count = 0;
		queue->front = NULL;
		queue->rear = NULL;
	}
	return (queue);
}

bool	is_empty(t_queue *queue)
{
	return (queue->rear == NULL);
}

void	enqueue(t_queue *queue, t_node *new)
{
	if (is_empty(queue) == true)
		queue->front = new;
	else
		queue->rear->link = new;
	queue->rear = new;
	queue->count++;
}

void	*dequeue(t_queue *queue)
{
	t_node	*temp;
	void	*data;

	if (is_empty(queue) == false)
	{
		temp = queue->front;
		data = temp->name;
		queue->front = temp->link;
		destroy_node(&temp);
		queue->count--;
		return (data);
	}
	return (NULL);
}
