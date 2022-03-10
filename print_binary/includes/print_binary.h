/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:18:06 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/10 22:34:36 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PRINT_BINARY_H

#	include <unistd.h>
#	include <stdlib.h>
#	include <stdio.h>

#	define	SIZE 32

#endif

//////// calcul.c

void	translate_to_bin(char bin_expr[SIZE + 1], const int nb);
int		get_bit(int nb, int pow_two);
int		get_max_bit(const int nb);

//////// display.c

void	display_bin(char bin_expr[SIZE + 1]);
