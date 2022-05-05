/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_ft_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:05:19 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/05 11:21:21 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define WHITESPACES " \t\n"
#define SKIP_WHITESPACES true
#define SKIP_WORD false
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

char	*ft_strchr(const char *str, const char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)(str + i));
		++i;
	}
	return (NULL);
}

void	ft_strncpy(char *dest, const char *src, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		++i;
	}
}

char	*skip_sequence(char **str, bool evaluation)
{
	while (**str != '\0' && (ft_strchr(WHITESPACES, **str) != NULL) == evaluation)
		++*str;
	return (*str);
}

size_t	get_numbof_words(const char *str)
{
	size_t	count;
	char	*str_ptr;	

	count = 0;
	str_ptr = (char *)str;
	skip_sequence(&str_ptr, SKIP_WHITESPACES);
	while (*str_ptr != '\0')
	{
		++count;
		skip_sequence(&str_ptr, SKIP_WORD);
		skip_sequence(&str_ptr, SKIP_WHITESPACES);
	}
	return (count);
}

char	**ft_split(char *str)
{
	const size_t	numbof_words = get_numbof_words(str);
	size_t			size;
	size_t			i;
	char			**strs;
	char			*str_ptr;

	strs = (char **)malloc((numbof_words + 1) * sizeof(char *));
	if (strs != NULL)
	{
		i = 0;
		str_ptr = str;
		while (i < numbof_words)
		{
			skip_sequence(&str_ptr, SKIP_WHITESPACES);
			size = ft_strlen(str_ptr);
			skip_sequence(&str_ptr, SKIP_WORD);
			size -= ft_strlen(str_ptr);
			strs[i] = (char *)malloc((size + 1) * sizeof(char));
			if (strs[i] != NULL)
			{
				ft_strncpy(strs[i], skip_sequence(&str, SKIP_WHITESPACES), size);
				strs[i][size] = '\0';
				str += size;
			}
			++i;
		}
	}
	strs[numbof_words] = NULL;
	return (strs);
}

int	main(int ac, char **av)
{
	char	**strs = ft_split(av[1]);
	size_t	i;

	(void)ac;
	i = 0;
	while (strs[i] != NULL)
	{
		printf("%s\n", strs[i]);
		++i;
	}
	return (EXIT_SUCCESS);
}
