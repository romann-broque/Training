/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:03:00 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 14:52:54 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	display_list(t_list **list, void (*display_fct)(), const char *delim)
{
	if (*list != NULL)
	{
		display_fct((*list)->data);
		if ((*list)->next != NULL)
		{
			ft_putstr(delim);
			display_list(&(*list)->next, display_fct, delim);
		}
		else
			ft_putstr("\n");
	}
	else
		ft_putstr("\n");
}
