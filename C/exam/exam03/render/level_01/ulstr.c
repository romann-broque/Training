/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:05:57 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/23 15:20:54 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define FIRST_UP 'A' // overkill
#define LAST_UP 'Z' // overkill
#define FIRST_LOW 'a' //overkill
#define LAST_LOW 'z' // overkill
#define SHIFT_CASE 32
#define NEW_LINE "\n" 

static size_t	ft_strlen(const char * const str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

static void	ft_putstr(const char * const str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}

static void	ulstr(char * const str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= FIRST_UP && str[i] <= LAST_UP) // isupper
			str[i] += SHIFT_CASE; // tolower
		else if (str[i] >= FIRST_LOW && str[i] <= LAST_LOW) // islower
			str[i] -= SHIFT_CASE; // toupper
		++i;
	}
}

int	main(int ac, char **av)
{
	char	*str; // inutile

	if (ac == 2)
	{
		str = av[1]; // inutile
		ulstr(str); // direct av[1]
		ft_putstr(str);
	}
	ft_putstr(NEW_LINE);
	return (EXIT_SUCCESS);
}
