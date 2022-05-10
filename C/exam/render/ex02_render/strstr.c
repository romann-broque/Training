/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:11:27 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/04 12:13:47 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#define EMPTY_STR ""

bool	ft_is_same_begin(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (false);
		++i;
	}
	return (str2[i] == '\0');
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*extract;
	size_t	i;

	i = 0;
	extract = NULL;
	if (*haystack == '\0' && *needle == '\0')
		extract = EMPTY_STR;
	while (haystack[i] != '\0')
	{
		if (ft_is_same_begin(haystack + i, needle) == true)
		{
			extract = (char *)(haystack + i);
			break ;
		}
		++i;
	}
	return (extract);
}


int main(int ac, char **av)
{
	(void)ac;
	printf("[%s]\n[%s]\n", ft_strstr(av[1], av[2]), strstr(av[1], av[2]));
	return 0;
}

