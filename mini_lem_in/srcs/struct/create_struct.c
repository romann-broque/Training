/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:14:09 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/17 22:18:28 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

node	*create_node(char *name)
{
	node	*new;

	new = (node *)malloc(sizeof(node));
	if (new != NULL)
	{
		new->link = NULL;
		new->link_cnt = 0;
		new->id = name;
	}
	return (new);
}

node	*add_node(node *n1, node *n2)
{
	node	*new;
	size_t	i;

	new = create_node(n1->id);
	new->id = n1->id;
	new->link_cnt = n1->link_cnt + 1;
	new->link = (node **)malloc((n1->link_cnt + 1) * sizeof(node *));
	if (new->link != NULL)
	{
		i = 0;
		while (i < new->link_cnt - 1)
		{
			new->link[i] = (node *)malloc(sizeof(node));
			if (n1->link != NULL)
				new->link[i] = n1->link[i];
			++i;
		}
		new->link[new->link_cnt - 1] = n2;
	}
	return (new);
}

void	display_node(node *n)
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
