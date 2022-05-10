/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:41:17 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 12:04:22 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	error_manager(t_result error)
{
	const char	*error_message[NBOF_ERROR] = {"UNKNOWN_COMMAND",
		"INCOMPLETE_GRAPH",
		"START_NOT_UNIQUE",
		"END_NOT_UNIQUE",
		"INVALID_NAME"};

	if (error != E_NO_ERROR)
	{
		ft_putstr("ERROR: ");
		ft_putendl(error_message[error - 1]);
	}
}
