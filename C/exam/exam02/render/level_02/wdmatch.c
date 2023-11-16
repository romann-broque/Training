/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:39:20 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/17 11:49:30 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *const str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

static void	ft_putstr(const char *const str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}

static void	wdmatch(const char *const str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (*str2 != '\0')
	{
		if (str1[i] == *str2)
			++i;
		++str2;
	}
	if (str1[i] == '\0')
		ft_putstr(str1);
}

int	main(int ac, char **av)
{
	if (ac == 3 && av[1] != NULL && av[2] != NULL)
		wdmatch(av[1], av[2]);
	ft_putstr("\n");
	return (EXIT_SUCCESS);
}
