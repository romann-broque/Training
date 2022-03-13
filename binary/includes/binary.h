/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:32:22 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 15:55:11 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_H

# define BINARY_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BYTE_SIZE 8
# define NUMB_OF_BITS 32

//////// print_binary.c

void	print_binary(const int nb);

//////// endian_toggle.c

int		endian_toggle(const int nb);

//////// calcul.c

void	translate_to_bin(char bin_expr[NUMB_OF_BITS + 1], const int nb);
int		get_bit(int nb, int pow_two);

//////// display.c

void	display_bin(char bin_expr[NUMB_OF_BITS + 1]);

#endif
