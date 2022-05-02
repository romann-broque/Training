/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_path_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:55:22 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 19:55:37 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	display_path_list(t_list *path_list)
{
	t_list	*path;

	if (path_list != NULL)
	{
		path = path_list->data;
		display_list(&path, display_room);
		display_path_list(path_list->next);
	}
}
