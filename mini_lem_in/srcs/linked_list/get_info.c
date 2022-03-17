/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:41:16 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/17 23:18:41 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

size_t	get_size(t_node **prev)
{
	if (*prev != NULL)
		return (1 + get_size(&(*prev) -> link));
	return (0);
}
