/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:55:29 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/03 23:52:01 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	is_in(const char c, const char *word)
{
	size_t	i;

	i = 0;
	while (word[i] != '\0')
	{
		if (word[i] == c)
			return (1);
		++i;
	}
	return (0);
}

static size_t	get_word_number(const char *str, const char *delimiters)
{
	int		dejavu;
	size_t	word_number;
	size_t	i;

	word_number = 0;
	dejavu = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_in(str[i], delimiters) == 0)
		{
			if (dejavu == 0)
			{
				++word_number;
				dejavu = 1;
			}
		}
		else
			dejavu = 0;
		++i;
	}
	return (word_number);
}

static size_t	get_word_size(const char *word, const char *delimiters)
{
	size_t	size;

	size = 0;
	while ((is_in(word[size], delimiters) == 0) && (word[size] != '\0'))
		++size;
	return (size);
}

static char	*getword(const char *input, size_t size)
{
	size_t	i;
	char	*word;

	word = (char *)malloc((size + 1) * sizeof(char));
	if (word != NULL)
	{
		i = 0;
		while (i < size)
		{
			word[i] = input[i];
			++i;
		}
		word[i] = '\0';
	}
	return (word);
}

static size_t	get_delimiters_number(const char *input, const char *delimiters)
{
	size_t	delimiters_number;

	delimiters_number = 0;
	while ((is_in(input[delimiters_number], delimiters) == 1))
		++delimiters_number;
	return (delimiters_number);
}

static void	desalloc(char **strs, size_t max)
{
	size_t	i;

	i = 0;
	while (i < max)
	{
		free(strs[i]);
		++i;
	}
	free(strs);
	strs = NULL;
}

static char	**str_split(const char *input, const char *delim)
{
	size_t	word_number;
	size_t	word_size;
	size_t	i;
	char	**split_strs;

	word_number = get_word_number(input, delim);
	split_strs = (char **)malloc((word_number + 1) * sizeof(char *));
	split_strs[word_number] = NULL;
	i = 0;
	while (i < word_number)
	{
		word_size = get_word_size(input, delim);
		split_strs[i] = getword(input, word_size);
		if (split_strs[i] == NULL)
		{
			desalloc(split_strs, i);
			return (NULL);
		}
		input += word_size + get_delimiters_number(input + word_size, delim);
		++i;
	}
	return (split_strs);
}

int	main(int ac, char **av)
{
	char	**strs;

	if (ac != 3)
		return (EXIT_FAILURE);
	strs = str_split(av[1], av[2]);
	while ((*strs != NULL) && (strs != NULL))
	{	
		printf("%s\n", *strs);
		++(strs);
	}
	return (EXIT_SUCCESS);
}
