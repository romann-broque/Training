/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:29:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/23 19:59:20 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	dfs(t_room *start, t_room *end)
{
	t_node	*next;
	t_room	*curr_ro;

	printf("%s\n", start->id);
	if (start == end)
		return;
	next = start->link;
	while (next != NULL)
	{
		curr_ro = next->name;
		dfs(curr_ro, end);
		next = next->link;
	}
}

void	bfs(t_room *start, t_room *end)
{
	t_queue	*queue;
	t_room	*curr_r;
	t_node	*curr_n;

	queue = init_queue();
	enqueue(queue, start->link);
	printf("%s\n", (char *)start->id);
	start->discovered = true;
	while (is_empty(queue) == false)
	{
		curr_r = dequeue(queue);
		printf("%s\n", (char *)curr_r->id);
		curr_n = curr_r->link;
		if (curr_r == end)
			return;
		while (curr_n != NULL)
		{
			curr_r = curr_n->name;
			curr_n = curr_n->link;
			if (curr_r->discovered == false)
			{
				printf("%s\n", (char *)curr_r->id);
				curr_r->discovered = true;
				enqueue(queue, curr_n);
				printf("MT ? %d\n", is_empty(queue));
				display_queue(queue);
			}
		}
	}
}
