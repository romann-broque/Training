/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:16:21 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/06 00:14:20 by romannbroque     ###   ########.fr       */
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

void	*increment_ptr(void *array)
{
	++array;
	return (array);
} 

void	*decrement_ptr(void *array)
{
	--array;
	return (array);
}

void	*increment_byte(void *array)
{
	++(int)(*array);
	return (array);
}

void	*decrement_byte(void *array)
{
	--(int)(*array);
	return (array);
}

void	*print(void *array)
{
	ft_putchar(array[0]);
	return (array);
}

void	*while_start(void *array, const char *command)
{
	if (*array == 0)
	{
		while (*command != ']')
			++command;
	}
	return (array);
}

void	*while_end(void *array, const char *command)
{
	if (*array != 0)
	{
		while (*command != '[')
			--command;
	}
	return (array);
}
