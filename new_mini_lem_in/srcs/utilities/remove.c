/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:01:32 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 14:28:44 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	ft_bzero(void *array, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((uint8_t *)array)[i] = 0;
		++i;
	}
}

void	cut_str(char *str, const char c)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			ft_bzero(str + i, ft_strlen(str + i));
			break ;
		}
		++i;
	}
}

void	full_free(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
