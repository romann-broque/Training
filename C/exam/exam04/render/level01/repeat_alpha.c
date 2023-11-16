/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:12:46 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/27 14:39:12 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define NEW_LINE '\n'
#define NB_ARG 2

static void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

static size_t	get_alph_index(const char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A');
	if (c >= 'a' && c <= 'z')
		return (c - 'a');
	return (0);
}

static void	repeat_display(const char c, const size_t times)
{
	size_t	i;

	i = 0;
	while (i < times)
	{
		ft_putchar(c);
		++i;
	}	
}

static void	repeat_alpha(const char *const str)
{
	size_t	i;
	size_t	alph_index;

	i = 0;
	while (str[i] != '\0')
	{
		alph_index = get_alph_index(str[i]);
		ft_putchar(str[i]);
		if (alph_index > 0)
			repeat_display(str[i], alph_index);
		++i;
	}
}

int	main(int ac, char **av)
{
	int	ret_val;

	ret_val = EXIT_FAILURE;
	if (ac == NB_ARG)
	{
		repeat_alpha(av[1]);
		ret_val = EXIT_SUCCESS;
	}
	ft_putchar(NEW_LINE);
	return (ret_val);
}
