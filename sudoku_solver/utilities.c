/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:52:32 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/16 22:26:24 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	str_len(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

size_t	len(const char **str)
{
	size_t	len;

	len = 0;
	while (str[len] != NULL)
		++len;
	return (len);
}

void	desalloc(char **strs, size_t max)
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

