/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:54:42 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/17 22:12:58 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	inst(char *line)
{
	char	*arg1;
	char	*arg2;

	if (is_start_inst(line))
	{
		arg1 = get_arg_from_str(line + str_len(START_PATTERN), '\0');
		start(arg1);
		return (2);
	}
	else if (is_end_inst(line))
	{
		arg1 = get_arg_from_str(line + str_len(END_PATTERN), '\0');
		end(arg1);
		return (2);
	}
	else if (is_link_inst(line))
	{
		arg1 = get_arg_from_str(line, DELIM);
		arg2 = get_arg_from_str(line + str_len(arg1) + 1, '\0');
		link_nodes(arg1, arg2);
		return (2);
	}
	else
		return (EXIT_FAILURE);
}

void	start(char *arg)
{
	printf("Start : %s\n", arg);
}

void	end(char *arg)
{
	printf("END : %s\n", arg);
}

void	link_nodes(char *arg1, char *arg2)
{
	node	*n1;
	node	*n2;

	n1 = create_node(arg1);
	n2 = create_node(arg2);
	n1 = add_node(n1, n2);
	n2 = add_node(n2, n1);
	display_node(n1);
	display_node(n2);
}
