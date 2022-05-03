/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:20:18 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 11:46:06 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

t_result	get_inst(const char *line)
{
	t_graph		*graph = get_graph();
	char		*(*is_inst[])(const char *) = {is_start_inst,
										  is_end_inst,
										  is_link_inst};
	t_result	(*inst[])(t_graph *, const char *) = {start, end, ft_link};
	int			i;
	char		*arg;
	t_result	rt_value;

	i = 0;
	rt_value = E_UNKNOWN_COMMAND;
	if (line != NULL)
	{
		while (i < NBOF_COM)
		{
			arg = is_inst[i](line);
			if (arg != NULL)
			{
				rt_value = inst[i](graph, arg);
				free(arg);
				break ;
			}
			++i;
		}
	}
	error_manager(rt_value);
	return (rt_value);
}

t_result	display(const char *line)
{
	if (line != NULL)
		ft_putendl(line);
	return (EXIT_SUCCESS);
}
