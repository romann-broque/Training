/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:44:32 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/27 12:16:50 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H

# define LINKED_LIST_H

# include <stdlib.h>
# include <stdio.h>
# include "utilities.h"

# define	MIN_SIZE 1
# define	SEPARATOR "-"

typedef	struct	s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

///////////// display.c

void	display_list(t_list *prev);

///////////// get_info.c

size_t	get_size(t_list **prev);
bool	is_in_list(t_list *curr, void *name);

///////////// linked_list.c

t_list	*linked_list(int node_number, void *data);

///////////// pop.c

void	pop(t_list **prev);
void	cut(t_list **prev);
void	delete_data(t_list **prev, void *input_data);

///////////// push.c

void	add(t_list *prev, void *input_data);
void	insert(t_list **prev, void *input_data, size_t rank);
void	push(t_list **prev, void *input_data);

///////////// reverse.c

void	reverse_list(t_list **root);

//////////// struct.c

t_list	*create_list(void *input_data);
void	destroy_node(t_list **prev);
void	destroy_list(t_list **prev);

#endif
