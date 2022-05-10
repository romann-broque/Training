/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:41:16 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/06 19:41:19 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H

#	include "linked_list.h"

#endif

size_t	get_size(node **prev)
{
	if (*prev != NULL)
		return (1 + get_size(&(*prev) -> link));
	return (0);
}
