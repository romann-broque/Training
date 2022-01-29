/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_brackets_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:03:09 by romannbroque      #+#    #+#             */
/*   Updated: 2022/01/29 15:43:38 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define OPENED "{[("
#define CLOSED "}])"
#define INITIAL_CLOSE_CONTEXT '\0'

static size_t	strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

static bool	is_in(const char c, const char *word)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = strlen(word);
	while (i < len)
	{
		if (word[i] == c)
			return (true);
		++i;
	}
	return (false);
}

static char	closed(const char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = strlen(OPENED);
	while (i < len)
	{
		if (OPENED[i] == c)
			return (CLOSED[i]);
		++i;
	}
	return (c);
}

static bool	check_rec(const char **const ptr_str, const char close_context)
{
	char	next_close_context;

	while (**ptr_str != '\0')
	{
		if (is_in(**ptr_str, OPENED) == true)
		{
			next_close_context = closed(**ptr_str);
			++(*ptr_str);
			if (check_rec(ptr_str, next_close_context) == false)
				return (false);
		}
		else if (is_in(**ptr_str, CLOSED) == true)
			return (**ptr_str == close_context);
		++(*ptr_str);
	}
	return (close_context == INITIAL_CLOSE_CONTEXT);
}

static bool	are_brackets_closed(char *str)
{
	if (str == NULL)
		return (true);
	return (check_rec(&str, INITIAL_CLOSE_CONTEXT));
}
