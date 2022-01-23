/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:36:19 by romannbroque      #+#    #+#             */
/*   Updated: 2022/01/23 23:43:18 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

static size_t	mini_len(const char *a, const char *b)
{
	size_t	len;

	len = 0;
	while ((a[len] != '\0') && (b[len] != '\0'))
		++len;
	return (len);
}

static	size_t	size(char	**strs)
{
	size_t	size;

	size = 0;
	while (strs[size] != NULL)
		++size;
	return (size);
}

static	void	switching(char **strs, const size_t i, const size_t j)
{
	char	*word;

	word = strs[i];
	strs[i] = strs[j];
	strs[j] = word;
}

static	bool	is_bigger(const char *word1, const char *word2)
{
	size_t	minilen;
	size_t	iterator;
	bool	is_bigger;

	is_bigger = true;
	minilen = mini_len(word1, word2);
	iterator = 0;
	while (iterator < minilen)
	{
		if (word1[iterator] < word2[iterator])
			return (false);
		else if (word1[iterator] > word2[iterator])
			return (true);
		++iterator;
	}
	return (false);
}

static	char	**lexicographical_sort(char **strs)
{
	size_t	i;
	size_t	words_number;
	bool	is_changed;

	words_number = size(strs);
	is_changed = true;
	while (is_changed)
	{
		is_changed = false;
		i = 0;
		while (i < words_number - 1)
		{
			if (is_bigger(strs[i], strs[i + 1]))
			{
				switching(strs, i, i +1);
				is_changed = true;
			}
			++i;
		}
	}
	return (strs);
}
