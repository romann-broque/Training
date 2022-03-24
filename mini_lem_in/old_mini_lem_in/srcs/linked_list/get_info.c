/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:41:16 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/24 11:37:04 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

size_t	get_size(t_list **prev)
{
	if (*prev != NULL)
		return (1 + get_size(&(*prev) -> next));
	return (0);
}
