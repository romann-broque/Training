/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:05:48 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/18 17:20:23 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H

# define LINKED_LIST_H

# include "utilities.h"

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list	*create_list(const char *name);

#endif
