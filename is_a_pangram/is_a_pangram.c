/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_pangram.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:21:44 by romannbroque      #+#    #+#             */
/*   Updated: 2022/01/17 17:52:28 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

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
	if ((c >= 97) && (c <= 122))
		c -= 32;
	return (c);
}

bool	is_a_pangram(char *str)
{
	int		iterator;
	char	alphabet[26];
	char	character;

	iterator = 0;
	if (len_str(str) < 26)
		return (false);
	while (iterator < len_str(str))
	{
		character = upper(str[iterator]);
		if ((character >= 65) && (character <= 90))
			alphabet[character - 65] = character;
		iterator++;
	}
	if (len_str(alphabet) < 26)
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
{
	char	*str = "Sphinx of black quartz, judge my vow.";

	if (is_a_pangram(str))
		ft_putchar('T');
	else
		ft_putchar('F');
	ft_putchar('\n');
	return (0);
}
