/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:01:27 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 20:00:22 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circle.h"
#include <stdio.h>
#include <math.h>

void	fill(char *str, char c, size_t size)
{
	size_t	i;

	i = 0;
	while (i <= size)
	{
		str[i] = c;
		++i;
	}
}
/*
int		ft_sqrt(int nb)
{
	int sqrt;

	sqrt = 0;
	nb *= 10;
	while (nb / 2)
	{
		if (sqrt * sqrt >= nb)
			break;
		++sqrt;
	}
	printf("%d -> %d, %d\n", nb, sqrt, sqrt * sqrt);
	return (sqrt / 10 + sqrt % 10);
}
*/
void	circle(int radius)
{
	int		i;
	int		x;
	int		y;
	int		distance;
	char	map[4 * radius + 1][4 * radius + 1];

	i = 0;
	while (i <= 2 * radius)
	{
		fill(map[i], ' ', 2 * radius);
		++i;
	}

////

	y = -radius;
	while (y <= radius)
	{
		distance = sqrt((radius * radius) - (abs(y) * (abs(y) - 1)));
		x = -distance;
		while (x <= distance)
		{
			map[radius + x][radius + y] = CHAR;
			++x;
		}
		++y;
	}

//// display

	i = 0;
	while (i <= 2 * radius)
	{
		for (int j = 0; j <= 2 * radius; ++j)
		{
			ft_putchar(map[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		++i;
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
		circle(atoi(av[1]));
	return (EXIT_SUCCESS);
}
