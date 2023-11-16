/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:58:20 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/23 18:56:40 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define NB_ARG 2
#define NEW_LINE '\n'
#define FIRST_WHITESPACE 8
#define LAST_WHITESPACE 13
#define SPACE ' '

static void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

static bool	is_whitespace(const char c)
{
	return (c == SPACE || (c >= FIRST_WHITESPACE && c <= LAST_WHITESPACE));
}

static size_t	get_last_letter_rank(const char *const str)
{
	size_t	i;
	size_t	rank;

	i = 0;
	rank = 0;
	while (str[i] != '\0')
	{
		if (is_whitespace(str[i]) == false)
			rank = i;
		++i;
	}
	return (rank);
}

static void	epur_str(const char *const str)
{
	const size_t	last_letter_rank = get_last_letter_rank(str);
	size_t			i;
	bool			is_single_whitespace;

	i = 0;
	is_single_whitespace = false;
	while (str[i] != '\0' && i <= last_letter_rank)
	{
		if (is_whitespace(str[i]) == true)
		{
			if (is_single_whitespace == true)
			{
				ft_putchar(str[i]);
				is_single_whitespace = false;
			}
		}
		else
		{
			ft_putchar(str[i]);
			is_single_whitespace = true;
		}
		++i;
	}
}

int	main(int ac, char **av)
{
	if (ac == NB_ARG)
	{
		epur_str(av[1]);
		ft_putchar(NEW_LINE);
		return (EXIT_SUCCESS);
	}
	ft_putchar(NEW_LINE);
	return (EXIT_FAILURE);
}
