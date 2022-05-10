/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:46:16 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 23:46:32 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

char	*ft_strndup(const char *str, size_t size)
{
	char	*new;

	new = (char *)malloc((size + 1) * sizeof(char));
	if (new != NULL)
		ft_strncpy(new, str, size);
	return (new);
}

char	*ft_strdup(const char *str)
{
	const size_t	size = ft_strlen(str);

	return (ft_strndup(str, size));
}

char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, const char *src)
{
	const size_t	size = ft_strlen(src);

	return (ft_strncpy(dest, src, size));
}
