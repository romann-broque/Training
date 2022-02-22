/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:52:32 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/22 18:48:26 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		sum_number_from_str(const char *str)
{
	size_t	i;
	size_t	len;
	int		sum;

	i = 0;
	len = str_len(str);
	sum = 0;
	while (i < len)
	{
		sum += get_n_from_char(str[i]);
		++i;
	}
	return (sum);
}

int		get_n_from_char(const char c)
{
	if ((c >= '1') && (c <= '9'))
		return (c - '0');
	return (0);
}

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

bool	are_double_numbers(const char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
			{
				if ((str[i] >= '1') && (str[i] <= '9'))
					return (true);
			}
			++j;
		}
		++i;
	}
	return (false);
}
