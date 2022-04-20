/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:27:37 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/20 14:21:46 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

char	*ft_strdup(const char *str)
{
	char			*cp_str;
	const size_t	len = ft_strlen(str);

	cp_str = (char *)malloc((len + 1) * sizeof(char *));
	if (cp_str != NULL)
		ft_strcpy(cp_str, str);
	return (cp_str);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(const char *str1, const char *str2)
{
	char	*new;
	size_t	size1;
	size_t	size2;

	if (str1 == NULL)
		str1 = "";
	if (str2 == NULL)
		str2 = "";
	size1 = ft_strlen(str1);
	size2 = ft_strlen(str2);
	new = (char *)malloc((size1 + size2 + 1) * sizeof(char));
	if (new != NULL)
	{
		ft_strcpy(new, str1);
		ft_strcpy(new + size1, str2);
	}
	return (new);
}

char	*ft_stradd(char **str1, const char *str2)
{
	char	*new;
	size_t	size1;
	size_t	size2;

	if (*str1 == NULL && str2 == NULL)
		return (NULL);
	else if (*str1 == NULL)
		return (ft_strdup(str2));
	else if (str2 == NULL)
		return (*str1);
	size1 = ft_strlen(*str1);
	size2 = ft_strlen(str2);
	new = (char *)malloc((size1 + size2 + 1) * sizeof(char));
	if (new != NULL)
	{
		ft_strcpy(new, *str1);
		ft_strcpy(new + size1, str2);
	}
	free(*str1);
	*str1 = NULL;
	return (new);
}

char	*ft_strchr(char *str, const char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
		++i;
	}
	return (NULL);
}
