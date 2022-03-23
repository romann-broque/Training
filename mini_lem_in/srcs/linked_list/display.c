/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:41:04 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/22 18:06:21 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	display_list(t_node *prev)
{
	if (prev != NULL)
	{
		printf("%s%p", SEPARATOR, prev->name);
		if (prev->link != NULL)
			display_list(prev->link);
		else
			printf("%s", SEPARATOR);
	}
}
