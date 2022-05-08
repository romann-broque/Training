/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:13:54 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/08 16:38:08 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

void	while_start(t_byte **array, const char **command)
{
	int	count;

	if (**array == 0)
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
}

void	while_end(t_byte **array, const char **command)
{
	int	count;

	if (**array != 0)
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
}
