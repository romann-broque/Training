/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:21:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/08 16:19:12 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

static char	get_closed_complement(const char c)
{
	const char	*ptr = ft_strchr(OPENED, c);

	if (ptr != NULL)
		return (CLOSED[ft_strlen(CLOSED) - ft_strlen(ptr)]);
	return (c);
}

static bool	check_rec(const char **const str, const char close_context)
{
	char	next_close_context;

	while (**str != '\0' && **str != close_context)
	{
		if (ft_strchr(OPENED, **str) != NULL
			|| ft_strchr(CLOSED, **str) != NULL)
		{
			next_close_context = get_closed_complement(**str);
			++(*str);
			if (check_rec(str, next_close_context) == false)
				return (false);
		}
		++(*str);
	}
	return (**str == close_context);
}

static bool	are_brackets_closed(const char *str)
{
	return (str == NULL || check_rec(&str, INITIAL_CONTEXT));
}

int	main(int ac, char **av)
{
	const char	*result[] = {"ERROR", "OKAY"};
	size_t		i;

	i = 1;
	while (i < ac)
	{
		ft_putstr(result[are_brackets_closed(av[i])]);
		++i;
	}
	ft_putstr("\n");
	return (EXIT_SUCCESS);
}
