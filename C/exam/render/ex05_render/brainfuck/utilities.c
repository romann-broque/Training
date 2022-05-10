/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:13:20 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/06 16:13:42 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

void	ft_bzero(void *ptr, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((uint8_t *)ptr)[i] = 0;
		++i;
	}
}
