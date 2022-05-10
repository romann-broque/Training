/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_losange_rec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:18:27 by romannbroque      #+#    #+#             */
/*   Updated: 2022/01/24 12:51:27 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

static void	repeat_ft_putchar(const char c, const unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		++i;
	}
}

static void	line(const unsigned int current_width, const unsigned int max,
					const char c)
{
	if (current_width != max)
	{
		repeat_ft_putchar(' ', max - current_width - 1);
		ft_putchar(c);
		if (current_width != 0)
		{	
			repeat_ft_putchar(' ', 2 * current_width - 1);
			ft_putchar(c);
		}
		ft_putchar('\n');
	}
}

static void	print_losange_rec(const unsigned int size,
								const unsigned int max_size, const char c)
{
	if (size < max_size)
	{
		line(size, max_size, c);
		print_losange_rec(size + 1, max_size, c);
		if (size + 1 != max_size)
			line(size, max_size, c);
	}
}

static void	print_losange(const int n, const char c)
{
	if (n > 0)
		print_losange_rec(0, (unsigned int)n, c);
}
