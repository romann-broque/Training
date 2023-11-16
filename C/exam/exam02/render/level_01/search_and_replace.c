/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:52:09 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/17 11:14:49 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

static void	ft_putstr(const char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}

static void	search_and_replace(char *str, const char c1, const char c2)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c1)
			str[i] = c2;
		++i;
	}
	ft_putstr(str);
}

int	main(int ac, char **av)
{
	if (ac == 4 && av[1] != NULL && av[2] != NULL && av[3] != NULL
		&& ft_strlen(av[2]) == 1 && ft_strlen(av[3]) == 1)
		search_and_replace(av[1], *av[2], *av[3]);
	ft_putstr("\n");
	return (EXIT_SUCCESS);
}
