/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:48:46 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/17 10:49:03 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define ROTATION 13
#define ALPHABET_SIZE 26
#define FIRST_LOW_LETTER 'a'
#define LAST_LOW_LETTER 'z'
#define FIRST_UP_LETTER 'A'
#define LAST_UP_LETTER 'Z'

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

static char	shift(const char c, const char last)
{
	int	new;

	new = (c + ROTATION);
	if (new > last)
		new -= ALPHABET_SIZE;
	return ((char)new);
}

static char	rotate(const char c)
{
	if (c >= FIRST_UP_LETTER && c <= LAST_UP_LETTER)
		return (shift(c, LAST_UP_LETTER));
	else if (c >= FIRST_LOW_LETTER && c <= LAST_LOW_LETTER)
		return (shift(c, LAST_LOW_LETTER));
	return (c);
}

void	rot13(char *str)
{
	size_t	i;

	if (str == NULL)
		return;
	i = 0;
	while (str[i] != '\0')
	{
		str[i] = rotate(str[i]);
		++i;
	}
	ft_putstr(str);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		rot13(av[1]); 
	return (EXIT_SUCCESS);
}
