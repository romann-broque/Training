/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:22:24 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/27 18:23:51 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	add(const int nb1, const int nb2)
{
	return (nb1 + nb2);
}

long	sub(const int nb1, const int nb2)
{
	return (nb1 - nb2);
}

long	mult(const int nb1, const int nb2)
{
	return (nb1 * nb2);
}

long	divide(const int nb1, const int nb2)
{
	if (nb2 == 0)
		return (0);
	return (nb1 / nb2);
}

long	mod(const int nb1, const int nb2)
{
	if (nb2 == 0)
		return (0);
	return (nb1 / nb2);
}
