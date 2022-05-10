/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:14:43 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/08 16:37:06 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

void	increment_ptr(t_byte **array)
{
	++(*array);
}

void	decrement_ptr(t_byte **array)
{
	--(*array);
}

void	increment_byte(t_byte **array)
{
	++(**array);
}

void	decrement_byte(t_byte **array)
{
	--(**array);
}

void	print(t_byte **array)
{
	ft_putchar(**array);
}
