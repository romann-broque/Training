/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:28:19 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 15:57:00 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary.h"

int	main(int ac, char **av)
{
	const int	arg = atoi(av[1]);

	if (ac > 1)
	{
		print_binary(arg);
		print_binary(endian_toggle(arg));
	}
	return (EXIT_SUCCESS);
}
