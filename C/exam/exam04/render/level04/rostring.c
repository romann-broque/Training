/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:09:26 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/27 19:32:06 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#define EXPECTED_NB_ARGS 2
#define NEW_LINE "\n"
#define SPACE_PATTERN " "
#define SPACE ' '
#define FIRST_WHITESPACE 8
#define LAST_WHITESPACE 13

static size_t	ft_strlen(const char *const str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

static void	ft_putstr(const char *const str)
{
	write(STDOUT_FILENO, str, ft_strlen(str) * sizeof(char));
}

static bool	is_whitespace(const char c)
{
	return (c == SPACE || (c >= FIRST_WHITESPACE && c <= LAST_WHITESPACE));
}

static const char	*skip_word(const char *str)
{
	while (*str != '\0' && is_whitespace(*str) == false)
		++str;
	return (str);
}

static const char	*skip_whitespaces(const char *str)
{
	while (*str != '\0' && is_whitespace(*str) == true)
		++str;
	return (str);
}

static char	*ft_strndup(const char *str, const size_t size)
{
	char	*new;
	size_t	i;

	new = (char *)malloc((size + 1) * sizeof(char));
	if (new != NULL)
	{
		i = 0;
		while (i < size)
		{
			new[i] = str[i];
			++i;
		}
		new[size] = '\0';
	}
	return (new);
}


static const char *to_next_word(const char *str)
{
	return skip_whitespaces(skip_word(str));
}

static void	rostring(const char *str)
{
	char	*first_word;
	char	*curr_word;

	str = skip_whitespaces(str);
	first_word = ft_strndup(str, skip_word(str) - str);
	str = to_next_word(str);
	while (*str != '\0')
	{
		curr_word = ft_strndup(str, skip_word(str) - str);
		ft_putstr(curr_word);
		free(curr_word);
		str = to_next_word(str);
		ft_putstr(SPACE_PATTERN);
	}
	ft_putstr(first_word);
	free(first_word);
}

int	main(int ac, char **av)
{
	int	ret_val;

	ret_val = EXIT_FAILURE;
	if (ac == EXPECTED_NB_ARGS)
	{
		rostring(av[1]);
		ret_val = EXIT_SUCCESS;
	}
	ft_putstr(NEW_LINE);
	return (ret_val);
}
