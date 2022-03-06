/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:21:39 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/05 18:31:35 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_list(node *prev)
{
	if (prev != NULL)
	{
		printf("%s%d", SEPARATOR, prev -> data);
		if (prev -> link != NULL)
			display_list(prev -> link);
		else
			printf("%s\n", SEPARATOR);
	}
}
