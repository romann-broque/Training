/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:28:41 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/08 22:32:06 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

static size_t	get_rank(const char *str, const char c)
{
	size_t	rank;

	rank = 0;
	while (str[rank] != '\0' && str[rank] != c)
		++rank;
	return (rank);
}

static void	interpreter(t_byte *array, const char **command)
{
	static void	(*operator_fct[NBOF_OPERATORS])(t_byte **) = {
		increment_ptr, decrement_ptr, increment_byte, decrement_byte, print};
	static void	(*while_fct[NBOF_WHILE])(t_byte **, const char **) = {
		while_start, while_end};
	size_t		op;

	if (**command != '\0')
	{
		op = get_rank(OPERATORS, **command);
		if (op < NBOF_OPERATORS + NBOF_WHILE)
		{
			if (op < NBOF_WHILE)
				while_fct[op](&array, command);
			else
			{
				op -= NBOF_WHILE;
				operator_fct[op](&array);
			}
		}
		++(*command);
		interpreter(array, command);
	}
}

void	brain_fuck(const char *command)
{
	t_byte	*array;

	array = (void *)malloc(2048);
	if (array != NULL)
	{
		ft_bzero(array, 2048);
		interpreter(array, &command);
	}
	ft_bzero(array, 2048);
	free(array);
}

int	main(int ac, char **av)
{
	(void)ac;
	if (av[1] != NULL)
		brain_fuck(av[1]);
	return (EXIT_SUCCESS);
}
