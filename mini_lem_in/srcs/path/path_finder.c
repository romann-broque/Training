/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:29:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/23 11:44:13 by romannbroque     ###   ########.fr       */
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
	t_node	*adj;
	t_room	*next;

	start->discovered = true;
	printf("%s\n", start->id);
	if (start == end)
		return;
	adj = start->link;
	while (adj != NULL)
	{
		next = adj->name;
		printf("%s\n", next->id);
		if (next == end)
			return;
		adj = adj->link;
	}
	adj = start->link;
	while (adj != NULL)
	{
		next = adj->name;
		if (next->discovered == false)
		{
			printf("...%s\n", next->id);
			bfs(next, end);
		}
		adj = adj->link;
	}
}
