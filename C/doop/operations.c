/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:49:36 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/25 10:02:52 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long	add(long n1, long n2)
{
	return (n1 + n2);
}
long	sub(long n1, long n2)
{
	return (n1 - n2);
}
long	mult(long n1, long n2)
{
	return (n1 * n2);
}
long	division(long n1, long n2)
{
	if (n2 == 0)
		division_by_zero_error();
	return (n1 / n2);
}
long	mod(long n1, long n2)
{
	if (n2 == 0)
		division_by_zero_error();
	return (n1 % n2);
}
