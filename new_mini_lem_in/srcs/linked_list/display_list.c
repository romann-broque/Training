/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:03:00 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 11:16:45 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	display_list(t_list **list, void (*display_fct)())
{
	if (*list != NULL)
	{
		ft_putstr(DELIM);
		display_fct((*list)->data);
		display_list(&(*list)->next, display_fct);
	}
	else
		ft_putstr(DELIM);
} 