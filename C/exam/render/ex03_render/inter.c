/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:16:16 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/04 12:58:44 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(const char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

char	*ft_strnchr(const char *str, const char c, size_t size)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && i < size)
	{
		if (str[i] == c)
			return ((char *)(str + i));
		++i;
	}
	return (NULL);
}

void	inter(const char *str1, const char *str2)
{
	size_t	i;
	size_t	j;

	if (str1 != NULL && str2 != NULL)
	{
		i = 0;
		while (str1[i] != '\0')
		{
			j = 0;
			while (str2[j] != '\0')
			{
				if (str1[i] == str2[j] && ft_strnchr(str1, str2[j], i) == NULL)
				{
					ft_putchar(str1[i]);
					break ;
				}
				++j;
			}
			++i;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac > 2)
		inter(av[1], av[2]);
	ft_putchar('\n');
	return (0);
}
