/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fibonacci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:20:48 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/24 17:57:59 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 27531

static void	ft_bzero(void *array, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((uint64_t *)(array))[i] = 0;
		++i;
	}
}

static unsigned long	fib(const unsigned int nb, unsigned long *const ptr)
{
	if (ptr[nb] != 0)
		return (ptr[nb]);
	if (nb == 0)
		return (0);
	if (nb == 1)
		return (1);
	ptr[nb] = fib(nb - 1, ptr) + fib(nb - 2, ptr);
	return (ptr[nb]);
}

int	main(int ac, char **av)
{
	long			nb;
	unsigned long	*ptr;


	(void)(av[1]);
	if (ac > 1)
	{
		nb = atoi(av[1]);
		if (nb >= 0 && nb <= MAX)
		{
			ptr = (unsigned long *)malloc((nb + 1) * sizeof(unsigned long));
			if (ptr != NULL)
			{
				ft_bzero(ptr, nb + 1);
				printf("%lu\n", fib(nb, ptr));
			}
		}
	}
	return (EXIT_SUCCESS);
}
