/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:55:55 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/12 15:38:20 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	main(int ac, char **av)
{
	char	*path_file;

	if (ac > 1)
	{
		path_file = av[1];
		display_file(path_file);
	}
	return (EXIT_SUCCESS);
}
