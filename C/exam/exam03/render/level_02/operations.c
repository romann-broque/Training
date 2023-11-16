/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:42:48 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/23 15:32:00 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	add(const int nb1, const int nb2)
{
	return (nb1 + nb2);
}

int	sub(const int nb1, const int nb2)
{
	return (nb1 - nb2);
}

int	mult(const int nb1, const int nb2)
{
	return (nb1 * nb2);
}

int	division(const int nb1, const int nb2)
{
	if (nb2 == 0)
		return (0);
	return (nb1 / nb2);
}

int	mod(const int nb1, const int nb2)
{
	if (nb2 == 0)
		return (0);
	return (nb1 % nb2);
}
