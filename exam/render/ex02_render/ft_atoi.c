/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:33:34 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/08 15:47:38 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

bool	is_neg(const char *str)
{
	return (*str == '-');
}

size_t	get_number_size(const char *str)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (*str == '-')
		++i;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		++i;
		++size;
	}
	return (size);
}

int		ft_atoi(const char *str)
{
	const size_t	nb_size = get_number_size(str);
	size_t			i;
	size_t			offset;
	int				decade;
	int				nb;

	nb = 0;
	if (nb_size > 0)
	{
		i = 0;
		decade = 1;
		offset = 1;
		if (is_neg(str) == true)
			offset = 0;
		while (i < nb_size)
		{
			nb += (str[nb_size - (i + offset)] - '0') * decade;
			decade *= 10;
			++i;
		}
		if (is_neg(str) == true)
			nb *= -1;
	}
	return (nb);
}

int	main(int ac, char **av)
{
	(void)ac;
	printf("atoi : %d\n", atoi(av[1]));
	printf("ft_atoi : %d\n", ft_atoi(av[1]));
	return (EXIT_SUCCESS);
}
