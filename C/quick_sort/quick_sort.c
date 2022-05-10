/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:18:03 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/10 18:00:14 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	swap(int *array, const int rank1, const int rank2)
{
	int	temp;

	temp = array[rank1];
	array[rank1] = array[rank2];
	array[rank2] = temp;
}

static size_t	partition(int *array, const int low, const int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
		{
			++i;
			swap(array, i, j);
		}
		++j;
	}
	swap(array, i + 1, high);
	return (i + 1);
}

static void	quick_sort(int *array, const int low, const int high)
{
	int	pivot_rank;

	if (low < high)
	{
		pivot_rank = partition(array, low, high);
		quick_sort(array, low, pivot_rank - 1);
		quick_sort(array, pivot_rank + 1, high);
	}
}

void	ascending_sort_array(int *array, const size_t size)
{
	quick_sort(array, 0, size - 1);
}

void	display_array(const int *array, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", array[i]);
		++i;
	}
	printf("\n"); 
}

int	main(void)
{
	int	array[10] = {1, 3, -5, 8, 5, 2, 42, 0, 1, -4};

	display_array(array, 10);
	ascending_sort_array(array, 10);
	display_array(array, 10);
}
