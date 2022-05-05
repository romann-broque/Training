/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:21:27 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/04 11:50:11 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_mean(const int *nbs, const size_t size)
{
	long	sum;
	size_t	i;

	if (nbs != NULL && size > 0)
	{
		sum = 0;
		i = 0;
		while (i < size)
		{
			sum += nbs[i];
			++i;
		}
		return (sum / size);
	}
	return (0);
}
