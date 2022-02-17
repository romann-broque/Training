/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:55:53 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/16 22:24:46 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**init_grid(char **lines, char **arg)
{
	size_t	i;

	i = 0;
	lines = (char **)malloc((SIZE_GRID + 1) * sizeof(char *));
	if (lines != NULL)
	{
		while (i < SIZE_GRID)
		{
			lines[i] = (char *)malloc((SIZE_GRID + 1) * sizeof(char));
			if (arg[i] != NULL)
			{
				lines[i] = arg[i + 1];
				++i;
			}
			else
			{
				desalloc(lines, SIZE_GRID + 1);
				break;
			}
		}
	}
	lines[i] = NULL;
	return (lines);
}
