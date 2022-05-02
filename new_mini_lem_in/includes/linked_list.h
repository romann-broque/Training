/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:05:48 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 10:10:37 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H

# define LINKED_LIST_H

# include "utilities.h"

# define DELIM "-"

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

/// create.c

t_list	*create_list(void *name, void *link);
void	add(t_list **parent, t_list *child);
void	add_element(t_list **list, void *element);

/// destroy.c

void	destroy(void *node, void destroy_fct());
void	cut(t_list **node, void (*destroy_fct)());
void	destroy_node(t_list **node, void (*destroy_fct)());
void	destroy_list(t_list **list, void (*destroy_fct)());
void	destroy_list_rec(t_list **head);

/// get_info_list.c

size_t	get_size_list(t_list *list);
bool	are_lists_equal(t_list *list1, t_list *list2);

/// display_list.c

void	display_list(t_list **list, void (*display_fct)());

#endif
