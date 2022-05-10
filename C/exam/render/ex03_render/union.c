/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:06:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/08 15:49:48 by romannbroque     ###   ########.fr       */
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

void	ft_union(const char *str1, const char *str2)
{
	size_t	i;
	size_t	j;

	if (str1 != NULL && str2 != NULL)
	{
		i = 0;
		while (str1[i] != '\0')
		{
			if (ft_strnchr(str1, str1[i], i) == NULL)
				ft_putchar(str1[i]);
			++i;
		}
		j = 0;
		while (str2[j] != '\0')
		{
			if (ft_strnchr(str2, str2[j], j) == NULL
				&& ft_strnchr(str1, str2[j], i) == NULL)
				ft_putchar(str2[j]);
			++j;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac > 2)
		ft_union(av[1], av[2]);
	ft_putchar('\n');
	return (0);
}
