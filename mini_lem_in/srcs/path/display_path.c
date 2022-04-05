/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:19:16 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/04 10:26:38 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	display_path_list(t_list *path_list)
{
	t_list	*curr_l;
	t_path	*curr_p;

	curr_l = path_list;
	curr_p = curr_l->data;
	while (curr_l != NULL && curr_p != NULL)
	{
		curr_p = curr_l->data;
		display_list_room(curr_p->step);
		curr_l = curr_l->next;
		free(curr_p);
	}
	free(curr_l);
}
