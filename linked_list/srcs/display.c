/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:41:04 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/06 19:41:09 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H

#	include "linked_list.h"

#endif

void	display_list(node *prev)
{
	if (prev != NULL)
	{
		printf("%s%d", SEPARATOR, prev->data);
		if (prev->link != NULL)
			display_list(prev->link);
		else
			printf("%s\n", SEPARATOR);
	}
}
