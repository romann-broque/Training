/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:14:09 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/17 23:45:21 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_room	*create_room(char *name)
{
	t_room	*new;

	new = (t_room *)malloc(sizeof(t_room));
	if (new != NULL)
	{
		new->link = NULL;
		new->link_cnt = 0;
		new->id = name;
	}
	return (new);
}

t_room	*add_room(t_room *n1, t_room *n2)
{
	t_room	*new;
	size_t	i;

	new = create_room(n1->id);
	new->id = n1->id;
	new->link_cnt = n1->link_cnt + 1;
	new->link = (t_room **)malloc((n1->link_cnt + 1) * sizeof(t_room *));
	if (new->link != NULL)
	{
		i = 0;
		while (i < new->link_cnt - 1)
		{
			new->link[i] = (t_room *)malloc(sizeof(t_room));
			if (n1->link != NULL)
				new->link[i] = n1->link[i];
			++i;
		}
		new->link[new->link_cnt - 1] = n2;
	}
	return (new);
}

void	display_room(t_room *n)
{
	size_t	i;

	i = 0;
	printf("%s : ADDRESS = %p ; ", n->id, n);
	printf("LINK_CNT = %zu\n", n->link_cnt);
	while (i < n->link_cnt)
	{
		printf("LINK = %p\n", n->link[i]);
		++i;
	}
}
