/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:13:54 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/06 18:54:43 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

void	*while_start(void **array, const char **command)
{
	int	count;

	if (**((uint8_t **)(array)) == 0)
	{
		count = 0;
		while (**command != WHILE_END || count != 0)
		{
			++(*command);
			if (**command == WHILE_START)
				++count;
			else if (**command == WHILE_END)
				--count;
		}
	}
	return (array);
}

void	*while_end(void **array, const char **command)
{
	int	count;

	if (**((uint8_t **)(array)) != 0)
	{
		count = 0;
		--(*command);
		while (**command != WHILE_START || count != 0)
		{
			if (**command == WHILE_END)
				++count;
			else if (**command == WHILE_START)
				--count;
			--(*command);
		}
	}
	return (array);
}
