/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:55:23 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/25 15:04:57 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	start(t_list **list, const char *command)
{
	t_list	*new;

	new = create_list(command + ft_strlen(START_PATTERN), NULL);
	add(list, new);
	return (EXIT_SUCCESS);
}

int	end(t_list **list, const char *command)
{
	t_list	*new;

	new = create_list(command + ft_strlen(END_PATTERN), NULL);
	add(list, new);
	return (EXIT_SUCCESS);
}

int	ft_link(t_list **list, const char *command)
{
	char	*arg1;
	char	*arg2;

	arg1 = ft_strtok(command, DELIM);
	arg2 = ft_strdup(arg1 + ft_strlen(DELIM));

	ft_putstr("LINK !\n");
	ft_putstr(arg1);
	ft_putstr(";");
	ft_putendl(arg2);
	display_list(list);
	free(arg1);
	free(arg2);
	return (EXIT_SUCCESS);
}
