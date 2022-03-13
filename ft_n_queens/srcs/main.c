/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:13:27 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 23:14:09 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_n_queens.h"

int	main(void)
{
	printf("There are %d distinct solutions.\n",
									ft_n_queens());
	return (EXIT_SUCCESS);
}
