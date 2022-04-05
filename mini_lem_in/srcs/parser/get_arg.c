/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:15:41 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/04 10:23:46 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

static unsigned int	get_arg_size_from_str(const char *str, const char end_char)
{
	unsigned int	size;

	size = 0;
	while (str[size] != '\0' && str[size] != end_char)
		++size;
	return (size);
}

char	*get_arg_from_str(const char *str, const char end_char)
{
	size_t				i;
	const unsigned int	size = get_arg_size_from_str(str, end_char);
	char				*arg;

	arg = (char *)malloc((size + 1) * sizeof(char));
	if (arg != NULL)
	{
		i = 0;
		while (i < size)
		{
			arg[i] = str[i];
			++i;
		}
		arg[size] = '\0';
	}
	return (arg);
}
