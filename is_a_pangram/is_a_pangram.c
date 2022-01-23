/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_pangram.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:21:44 by romannbroque      #+#    #+#             */
/*   Updated: 2022/01/21 23:50:37 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26
#define DELTA 32
#define A_RANK 97
#define Z_RANK 122
#define A_RANK_UPPER 65
#define Z_RANK_UPPER 90

static ssize_t	ft_putchar(const char c)
{
	return (write(STDOUT_FILENO, &c, sizeof(c)));
}

static size_t	strlen(const char *const str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static const char	toupper(const char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c - DELTA);
	return (c);
}

bool	is_a_pangram(char *str)
{
	int		i;
	char	alphabet[ALPHABET_SIZE];
	char	character;

	i = 0;
	while (i < strlen(str))
	{
		character = toupper(str[i]);
		if ((character >= A_RANK_UPPER) && (character <= Z_RANK_UPPER))
			alphabet[character - A_RANK_UPPER] = character;
		i++;
		if (strlen(alphabet) == ALPHABET_SIZE)
			return (true);
	}
	if (strlen(alphabet) < ALPHABET_SIZE)
		return (false);
	return (true);
}
