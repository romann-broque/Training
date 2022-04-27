/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:32:00 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/27 11:47:43 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	destroy_graph(t_graph **graph)
{
	destroy(&(*graph)->start, full_free);
	destroy(&(*graph)->end, full_free);
	destroy_list(&(*graph)->rooms, full_free);
}
