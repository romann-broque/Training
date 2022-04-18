/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:20:18 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/16 22:43:20 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

static int	start(const char *command)
{
	if (command != NULL)
		ft_putstr("START !\n");
	return (EXIT_SUCCESS);
}

static int	end(const char *command)
{
	if (command != NULL)
		ft_putstr("END !\n");
	return (EXIT_SUCCESS);
}

static int	ft_link(const char *command)
{
	if (command != NULL)
		ft_putstr("LINK !\n");
	return (EXIT_SUCCESS);
}

void	get_inst(const char *line)
{
	int		i;
	bool	(*is_inst[])(const char *) = {is_start_inst,
										  is_end_inst,
										  is_link_inst};
	int		(*inst[])(const char *) = {start, end, ft_link};

	i = 0;
	while (i < NBOF_COM)
	{
		if (is_inst[i](line) == true)
		{
			inst[i](line);
			break ;
		}
		++i;
	}
}
