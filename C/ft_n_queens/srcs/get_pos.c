/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:32:45 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 23:12:35 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_n_queens.h"

int	get_lign(int position)
{
	return (position / SIZE);
}

int	get_column(int position)
{
	return (position % SIZE);
}

int	get_pos_from_coord(int lign, int column)
{
	return (SIZE * lign + column);
}

int	next_pos(int position)
{
	return (position + 1);
}
