/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pascal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 01:16:40 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/24 15:04:56 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#define SPACE " "
#define SEPARATOR "  "

static void	display_array(const int *array, const size_t size)
{
	size_t	i;

	i = 0;
	printf("[");
	while (i < size)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf("%s", SEPARATOR);
		++i;
	}
	printf("]");
}

static int	get_nb(const unsigned int row, const unsigned int column)
{
	if (column <= 1 || column == row)
		return (1);
	return (get_nb(row - 1, column - 1) + get_nb(row - 1, column));
}

static int	*get_row(int rowIndex, int *returnSize)
{
	int	i;
	int	*row;

	row = (int *)malloc((rowIndex + 1) * sizeof(int));
	if (row != NULL)
	{
		i = 0;
		while (i <= rowIndex)
		{
			row[i] = get_nb(rowIndex + 1, i + 1);
			++i;
		}
	}
	*returnSize = rowIndex + 1;
	return (row);
}

static void	display_row(const int nb, const int spaces)
{
	int	i;
	int	*size;

	size = (int *)malloc(sizeof(int));
	if (size != NULL)
	{
		i = 0;
		while (i < spaces)
		{
			printf("%s", SPACE);
			++i;
		}
		display_array(get_row(nb, size), nb + 1);
	}
	free(size);
	printf("\n");
}

int	main(int ac, char **av)
{
	int	i;
	int	nb;

	if (ac > 1)
	{
		i = 0;
		nb = atoi(av[1]);
		while (i <= nb)
		{
			display_row(i, (nb - i));
			++i;
		}
	}
	return (EXIT_SUCCESS);
}
