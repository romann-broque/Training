/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:28:52 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/06 09:30:06 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	reverse(node **prev)
{
	size_t	i;
	size_t	size;
	node	*temp;

	if (get_size(prev) > 1)
	{
		i = MIN_SIZE;
		size = get_size(prev);
		while (i <= size)
		{
			temp = cut(prev);
			insert(prev, temp -> data, i);
			++i;
		}
	}
}
