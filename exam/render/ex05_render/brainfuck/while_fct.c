/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:13:54 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/06 16:42:50 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

void	*while_start(void **array, const char **command)
{
	size_t	count;

	if (**((uint8_t **)(array)) == 0)
	{
		count = 0;
		++(*command);
		while (**command != ']' || count != 0)
		{
//			if (**command == '[')
//				++count;
//			else if (**command == ']')
//				--count;
			++(*command);
		}
	}
	return (array);
}

void	*while_end(void **array, const char **command)
{
	size_t	count;

	if (**((uint8_t **)(array)) != 0)
	{
		count = 0;
		--(*command);
		while (**command != '[' || count != 0)
		{
//			if (**command == ']')
//				++count;
//			else if (**command == '[')
//				--count;
			--(*command);
		}
	}
	return (array);
}
