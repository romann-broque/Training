/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:22:12 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/25 12:02:14 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	invalid_numb_error(void)
{
	ft_putstr("ERROR : INVALID_NUMBER\n");
	exit(EXIT_FAILURE);
}

void	invalid_operator_error(void)
{
	ft_putstr("ERROR : INVALID_OPERATOR\n");
	exit(EXIT_FAILURE);
}

void	null_arg_error(void)
{
	ft_putstr("ERROR : NULL_ARGUMENT\n");
	exit(EXIT_FAILURE);
}

void	division_by_zero_error(void)
{
	ft_putstr("ERROR : DIVISION_BY_ZERO\n");
	exit(EXIT_FAILURE);
}
