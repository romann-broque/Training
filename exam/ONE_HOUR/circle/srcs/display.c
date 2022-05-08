/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:05:28 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 18:56:17 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circle.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

void	ft_putstr(const char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str) * sizeof(char));
}

void	display_map(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		++i;
	}
}
