/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:00:59 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/24 16:48:31 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_graph *init_graph(void)
{
	t_graph	*new;

	new = (t_graph *)malloc(sizeof(t_graph));
	if (new != NULL)
	{
		new->rooms = create_list(NULL);
		new->start = NULL;
		new->end = NULL;
	}
	return (new);
}
