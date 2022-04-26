/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:55:55 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/26 11:11:17 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	main(int ac, char **av)
{
	char	*path_file;
	t_list	*list;

	if (ac > 1)
	{
		path_file = av[1];
		read_file(path_file, display);
		ft_putstr("\n");
		list = read_file(path_file, get_inst);
		display_list(&list);
		ft_putstr("\n");
	}
	return (EXIT_SUCCESS);
}
