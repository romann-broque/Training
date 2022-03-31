/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:41:04 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/24 17:47:56 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	display_list(t_list *prev)
{
	if (prev != NULL)
	{
		printf("%s%p", SEPARATOR, prev->data);
		if (prev->next != NULL)
			display_list(prev->next);
		else
			printf("%s", SEPARATOR);
	}
}
