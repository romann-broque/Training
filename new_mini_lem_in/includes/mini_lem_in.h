/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:53:43 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/28 15:16:15 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LEM_IN_H

#define MINI_LEM_IN_H

# include "gnl.h"
# include "linked_list.h"
# include "utilities.h"

# define NBOF_SUITE 4
# define NBOF_COM 3
# define START_PATTERN "#start "
# define END_PATTERN "#end "
# define DELIM "-"
#define GET NULL

typedef struct s_graph
{
	t_list	*rooms;
	char	*start;
	char	*end;
}			t_graph;

typedef struct s_room
{
	char	*name;
	bool	lock;
	t_list	*neighboor;
}			t_room;

///////////////// GRAPH

///create_graph.c

t_graph *graph_keeper(t_graph *graph);
t_graph *get_graph(void);
void	init_graph(t_graph *);
void	set_graph(t_graph *graph);

///display_graph.c

void	display_graph(t_graph *graph);

///destroy_graph.c

void	destroy_graph(t_graph *);

///////////////// ROOM

/// create_room.c

t_room	*create_room(const char *input_name, t_list *list);

/// get_info_room.c

t_room	*find_room(t_list *list, const char *name);

/// destroy_room.c

void	destroy_room(t_room **room);

/// display_room.c

void	display_room(t_room *room);

///////////////// INSTRUCTIONS

///find_inst.c

bool	is_start_inst(const char *);
bool	is_end_inst(const char *);
bool	is_link_inst(const char *);

///exe_inst.c

int		start(t_graph *, const char *command);
int		end(t_graph *, const char *command);
int		ft_link(t_graph *, const char *command);

///instructions.c

void	get_inst(const char *);
void	display(const char *line);

#endif
