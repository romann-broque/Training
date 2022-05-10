/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 11:46:13 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/09 16:17:00 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

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

int	get_max_height(const int size)
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

char	get_char_to_display(const int current, const int total,
		const int size_max, const int height)
{
	char	char_to_display;
	int		door_zone_begin;
	int		door_zone_end;

	char_to_display = INSIDE;
	if (height > 0)
	{
		door_zone_begin = total / 2 - size_max / 2;
		door_zone_end = total / 2 + size_max / 2;
		if (current >= door_zone_begin && current <= door_zone_end)
		{
			if (size_max > INIT_HEIGHT
				&& current == door_zone_end - 1
				&& height == (get_max_height(size_max)
					+ get_max_height(size_max + 1)) / 2 + 2)
				char_to_display = HANDLE;
			else
				char_to_display = DOOR;
		}
	}
	return (char_to_display);
}

void	display_floor(const int nb_inside, const int nb_ext, const int size_max,
		const int height)
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
		ft_putchar(get_char_to_display(i, nb_inside,
				size_max, height));
		++i;
	}
	ft_putchar(RIGHT_EXT);
	ft_putchar('\n');
}

void	get_max_width(int size, int height, int *max_width, int shift)
{
	static int	size_max = -1;
	int			curr_width;
	int			nb_empty;

	if (size_max == -1)
		size_max = size;
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
		if (size != size_max || height <= get_max_height(size_max - 1)
			- size_max % 2 + INIT_HEIGHT)
			height = 0;
		display_floor(curr_width, nb_empty, size_max - 1, height);
	}
}

void	sastantua(const int size)
{
	const int	max_height = get_max_height(size);
	int			width;
	int			shift;

	width = INIT_WIDTH;
	shift = INIT_SHIFT * (size / 2 + size % 2 + 1);
	get_max_width(size, max_height, &width, shift);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		sastantua(atoi(av[1]));
	return (EXIT_SUCCESS);
}
