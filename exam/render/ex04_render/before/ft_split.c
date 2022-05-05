/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:05:19 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/04 16:44:11 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define DELIM " \t\n"

#include <stdio.h>

static size_t	ft_strnlen(const char *str1, const char *str2)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (str1[len] != '\0')
	{
		i = 0;
		while (str2[i] != '\0')
		{
			if (str1[len] == str2[i])
				return (len);
			++i;
		}
		++len;
	}
	return (len);
}

static size_t	count_delim_in_str(const char *str, const char *delim)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		i += ft_strnlen(str + i, delim);
		if (str[i] == '\0')
			break;
		++count;
		++i;
	}
	return (count);
}

static size_t	*set_len(const char *str, const size_t nbof_str)
{
	size_t	i;
	size_t	j;
	size_t	*lens;

	lens = (size_t *)malloc(nbof_str * sizeof(size_t));
	if (lens != NULL)
	{
		i = 0;
		j = 0;
		while (i < nbof_str)
		{
			j += ft_strnlen(str + j, DELIM);
			lens[i] = j;
			++j;
			++i;
		}
	}
	return (lens);
}

char	*ft_strncpy(char *dest, const char *src, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		++i;
	}
	return (dest);
}

char	**ft_split(char *str)
{
	const size_t	nbof_str = count_delim_in_str(str, DELIM);
	const size_t	*lens = set_len(str, nbof_str);
	size_t			i;
	size_t			j;
	char			**strs;

	printf("SPACES : %zu\n", nbof_str);
	strs = (char **)malloc((nbof_str + 1) * sizeof(size_t *));
	if (strs != NULL)
	{
		i = 0;
		j = 0;
		while (i < nbof_str)
		{
			printf("SIZE : %zu\n", lens[i]);
			strs[i] = (char *)malloc((lens[i] + 1) * sizeof(char));
			if (strs[i] != NULL)
			{
				strs[i] = ft_strncpy(strs[i], str + j, lens[i]);
				strs[i][lens[i]] = '\0';
			}
			++i;
		}
		strs[nbof_str] = NULL;
	}
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
		printf("%s", strs[i]);
		++i;
	}
	printf("\n");
	return (EXIT_SUCCESS);
}
