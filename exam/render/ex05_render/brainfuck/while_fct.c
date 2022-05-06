/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:13:54 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/06 17:27:53 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

void	*while_start(void **array, const char **command)
{
	int	count;

	if (**((uint8_t **)(array)) == 0)
	{
		count = 0;
		while (**command != ']' || count != 0)
		{
			++(*command);
			if (**command == '[')
				++count;
			else if (**command == ']')
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
		while (**command != '[' || count != 0)
		{
			if (**command == ']')
				++count;
			else if (**command == '[')
				--count;
			--(*command);
		}
	}
	return (array);
}
