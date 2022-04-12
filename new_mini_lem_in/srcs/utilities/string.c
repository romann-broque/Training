/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:27:37 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/12 15:58:40 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

char	*ft_strdup(const char *str)
{
	char			*cp_str;
	const size_t	len = ft_strlen(str);
	size_t			i;

	cp_str = (char *)malloc((len + 1) * sizeof(char *));
	if (cp_str != NULL)
	{
		i = 0;
		while (i < len)
		{
			cp_str[i] = str[i];
			++i;
		}
		cp_str[len] = '\0';
	}
	return (cp_str);
}

void	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
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
