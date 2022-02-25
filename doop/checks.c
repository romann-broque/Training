/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:49:27 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/24 16:33:16 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	is_numb(const char c)
{
	return ((c >= '0') && (c <= '9'));
}

bool	is_valid_number(char *str)
{
	str = trim(str);
	str += (*str == '-' || *str == '+');
	while (is_numb(*str) == true)
		++str;
	return (*str == '\0');
}
