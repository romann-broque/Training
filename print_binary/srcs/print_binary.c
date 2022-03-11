/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:46:39 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/11 14:04:52 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_binary.h"

void	print_binary(const int nb)
{
	char	bin_expr[SIZE + 1];

	bin_expr[0] = '0' + (nb < 0);
	translate_to_bin(bin_expr, nb);
	bin_expr[SIZE] = '\0';
	display_bin(bin_expr);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		print_binary(atoi(av[1]));
	return (EXIT_SUCCESS);
}
