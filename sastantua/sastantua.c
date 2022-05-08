/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 11:46:13 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/09 01:49:12 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#define EMPTY ' '
#define LEFT_EXT '/'
#define RIGHT_EXT '\\'
#define INSIDE '*'
#define DOOR '|'
#define HANDLE '$'
#define INIT_HEIGHT 3
#define INIT_WIDTH 1
#define INIT_SHIFT 1

static void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

void	display_floor(const int nb_inside, const int nb_ext)
{
	int	i;

	i = 0;
	while (i < nb_ext)
	{
		ft_putchar(EMPTY);
		++i;
	}
	i = 0;
	ft_putchar(LEFT_EXT);
	while (i < nb_inside)
	{
		ft_putchar(INSIDE);
		++i;
	}
	ft_putchar(RIGHT_EXT);
	ft_putchar('\n');
}

int		get_max_height(const int size)
{
	int	i;
	int	block_height;
	int	max_height;

	i = 0;
	block_height = INIT_HEIGHT;
	max_height = 0;
	while (i < size)
	{
		max_height += block_height;
		++block_height;
		++i;
	}
	return (max_height);
}

void	get_max_width(int size, const int height, int *max_width, int shift)
{
	int	curr_width;
	int	nb_empty;

	if (height > 0)
	{
		if (height <= get_max_height(size - 1))
		{
			if (size % 2 == 1)
				--shift;
			--size;
			*max_width += 2 * shift;
		}
		curr_width = *max_width;
		*max_width += 2;
		nb_empty = *max_width / 2 - 1;
		get_max_width(size, height - 1, max_width, shift);
		curr_width = *max_width - curr_width - 1;
		display_floor(curr_width, nb_empty);
	}
}

void	sastantua(const int size)
{
	const int	max_height = get_max_height(size);
	int 		width;
	int 		shift;

	width = INIT_WIDTH;
	shift = INIT_SHIFT * (size / 2 + 1) + (size % 2);
	get_max_width(size, max_height, &width, shift);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		sastantua(atoi(av[1]));
	return (EXIT_SUCCESS);
}
