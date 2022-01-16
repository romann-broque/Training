/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_losange.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:45:35 by romannbroque      #+#    #+#             */
/*   Updated: 2022/01/16 23:09:20 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(0, &c, 1);
}

void	repeat_ft_putchar(char c, int n)
{
	int	iterator;

	iterator = 0;
	while (iterator < n)
	{
		ft_putchar(c);
		iterator++;
	}
}

int	display_int(int int_space, const char c, int sign)
{
	ft_putchar(c);
	if (int_space > 1)
	{
		repeat_ft_putchar(' ', int_space);
		ft_putchar(c);
		int_space += 2 * sign;
	}
	ft_putchar('\n');
	int_space += 2 * sign;
	return (int_space);
}

void	print_losange(const int n, const char c)
{
	int	width;
	int	max_width;
	int	int_space;
	int	sign;

	width = 1;
	max_width = 2 * n;
	int_space = 1;
	sign = 1;
	if ((n >= 1) && (n <= 2147483647))
	{
		while ((width != max_width) && (width > 0))
		{
			repeat_ft_putchar(' ', 2 * n - (width - 1));
			int_space = display_int(int_space, c, sign);
			width += 2 * sign;
			if (width >= 2 * n)
			{
				max_width = 0;
				sign *= -1;
			}
		}
	}
}
