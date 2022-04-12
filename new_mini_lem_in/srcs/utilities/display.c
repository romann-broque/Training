/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:20:02 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/11 17:36:47 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	ft_putstr(const char *str)
{
	write(STDOUT_FILENO, str, sizeof(char) * ft_strlen(str));
}
