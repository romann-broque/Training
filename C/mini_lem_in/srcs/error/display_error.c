/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:49:45 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/04 10:32:41 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	display_error(int state)
{
	const char	*error_type[] =
								{"E_NO_ERROR",
								 "UKNOWN_COMMAND",
								 "START_DOESNT_EXIST",
								 "END_DOESNT_EXIST",
								 "MISSING_START",
								 "MISSING_END",
								 "MISSING_NODE",
								 "START_NOT_UNIQUE",
								 "END_NOT_UNIQUE",
								 "E_NO_NODE"};
	if (state != E_NO_ERROR)
	{
		printf("ERROR : %s\n", error_type[state]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
