/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:07:07 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/23 19:11:53 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#define NEW_LINE "\n"
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

static void	ft_strncpy(char *const dest, const char *const src,
				const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		++i;
	}
}

static size_t	get_word_size(const char *const str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0'
		&& (str[size] != SPACE
			&& (str[size] <= FIRST_WHITESPACE || str[size] >= LAST_WHITESPACE)))
		++size;
	return (size);
}

static char	*rev_wstr(const char *str)
{
	const size_t	size = ft_strlen(str);
	size_t			curr_wordsize;
	ssize_t			shift;
	char			*new;

	new = (char *)malloc((size + 1) * sizeof(char));
	if (new != NULL)
	{
		new[size] = '\0';
		curr_wordsize = get_word_size(str);
		shift = size;
		while (*str != '\0')
		{
			shift -= curr_wordsize;
			ft_strncpy(new + shift, str, curr_wordsize);
			str += curr_wordsize + (shift > 0);
			curr_wordsize = get_word_size(str);
			if (shift > 0)
			{
				--shift;
				new[shift] = SPACE;
			}
		}
	}
	return (new);
}

int	main(int ac, char **av)
{
	char	*rev_wstring;

	if (ac == 2)
	{
		rev_wstring = rev_wstr(av[1]);
		write(STDOUT_FILENO, rev_wstring, ft_strlen(rev_wstring));
		write(STDOUT_FILENO, NEW_LINE, ft_strlen(NEW_LINE));
		free(rev_wstring);
		return (EXIT_SUCCESS);
	}
	write(STDOUT_FILENO, NEW_LINE, ft_strlen(NEW_LINE));
	return (EXIT_FAILURE);
}
