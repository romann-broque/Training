/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:28:10 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/27 10:35:17 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_graph	*init_graph(void)
{
	t_graph	*new;

	new = (t_graph *)malloc(sizeof(t_graph));
	if (new != NULL)
	{
		new->rooms = NULL;
		new->start = NULL;
		new->end = NULL;
	}
	return (new);
}
