/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:03:00 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/26 10:03:36 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	display_list(t_list **list)
{
	if (*list != NULL)
	{
		ft_putstr(DELIM);
		ft_putstr((*list)->data);
		display_list(&(*list)->next);
	}
	else
		ft_putstr(DELIM);
}
