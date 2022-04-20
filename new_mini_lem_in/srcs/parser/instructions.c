/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:20:18 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/20 15:44:41 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

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
