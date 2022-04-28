/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:20:18 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 23:12:47 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

result	get_inst(const char *line)
{
	t_graph	*graph = get_graph();
	bool	(*is_inst[])(const char *) = {is_start_inst,
										  is_end_inst,
										  is_link_inst};
	result	(*inst[])(t_graph *, const char *) = {start, end, ft_link};
	int		i;
	result	rt_value;

	i = 0;
	rt_value = EXIT_FAILURE;
	if (line != NULL)
	{
		while (i < NBOF_COM)
		{
			if (is_inst[i](line) == true)
			{
				rt_value = inst[i](graph, line);
				break ;
			}
			++i;
		}
	}
	return (rt_value);
}

result	display(const char *line)
{
	if (line != NULL)
		ft_putendl(line);
	return (EXIT_SUCCESS);
}
