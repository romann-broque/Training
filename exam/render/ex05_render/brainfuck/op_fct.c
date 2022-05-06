/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:14:43 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/06 16:14:46 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

void	*increment_ptr(void **array)
{
	++(*array);
	return (array);
}

void	*decrement_ptr(void **array)
{
	--(*array);
	return (array);
}

void	*increment_byte(void **array)
{
	++(**((uint8_t **)(array)));
	return (array);
}

void	*decrement_byte(void **array)
{
	--(**((uint8_t **)(array)));
	return (array);
}

void	*print(void **array)
{
	ft_putchar(**((char **)(array)));
	return (array);
}
