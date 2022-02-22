/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:01:41 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/22 17:49:18 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//DISPLAY////////////

void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

void	ft_putstr(const char *str)
{
	if (*str != '\0')
		write(STDOUT_FILENO, str, sizeof(char) * (str_len(str) + 1));
}

void	display_line(const char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		ft_putchar(line[i]);
		ft_putchar(SPACE);
		++i;
	}
}

void	display_grid(char **grid)
{
	size_t	i;

	i = 0;
	while (grid[i] != NULL)
	{
		display_line(grid[i]);
		ft_putchar('\n');
		++i;
	}
}

void	display_error(void)
{
	ft_putstr("There isn't solution\n");
}

