/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_pangram.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:21:44 by romannbroque      #+#    #+#             */
/*   Updated: 2022/01/18 00:09:43 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26
#define A_RANK 97
#define Z_RANK 122
#define A_RANK_UPPER 65
#define Z_RANK_UPPER 90
#define DELTA 32

void	ft_putchar(char c)
{
	write(0, &c, 1);
}

int	len_str(char *str)
{
	int	iterator;

	iterator = 0;
	while (str[iterator] != '\0')
		iterator++;
	return (iterator);
}

char	upper(char c)
{
	if ((c >= A_RANK) && (c <= Z_RANK))
		c -= DELTA;
	return (c);
}

bool	is_a_pangram(char *str)
{
	int		iterator;
	char	alphabet[ALPHABET_SIZE];
	char	character;

	iterator = 0;
	if (len_str(str) < ALPHABET_SIZE)
		return (false);
	while (iterator < len_str(str))
	{
		character = upper(str[iterator]);
		if ((character >= A_RANK_UPPER) && (character <= Z_RANK_UPPER))
			alphabet[character - A_RANK_UPPER] = character;
		iterator++;
		if (len_str(alphabet) == ALPHABET_SIZE)
			return (true);
	}
	if (len_str(alphabet) < ALPHABET_SIZE)
		return (false);
	return (true);
}
