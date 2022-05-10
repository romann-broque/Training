/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:34:50 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/05 11:22:38 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_max(const int *nbs, const size_t size)
{
	int		max;
	size_t	i;

	i = 0;
	max = 0;
	if (nbs != NULL && size > 0)
	{
		max = nbs[i];
		while (i < size)
		{
			if (nbs[i] > max)
				max = nbs[i];
			++i;
		}
	}
	return (max);
}
