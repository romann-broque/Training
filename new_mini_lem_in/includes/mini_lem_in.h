/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:53:43 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 11:24:32 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LEM_IN_H

#define MINI_LEM_IN_H

# include "gnl.h"
# include "linked_list.h"
# include "utilities.h"

# define NBOF_SUITE 6
# define NBOF_COM 3
# define START_PATTERN "#start "
# define END_PATTERN "#end "
# define DELIM "-"
# define GET NULL

typedef struct s_room
{
	char	*name;
	bool	lock;
	t_list	*neighboor;
}			t_room;

typedef struct s_path
{
	t_list	*rooms;
	size_t	size;
}			t_path;

typedef struct s_graph
{
	t_list	*rooms;
	t_list	*shortest_paths;
	t_room	*start;
	t_room	*end;
}			t_graph;

///////////////// GRAPH

/// create_graph.c

t_graph *graph_keeper(t_graph *graph);
t_graph *get_graph(void);
void	init_graph(t_graph *);
void	set_graph(t_graph *graph);

/// display_graph.c

void	display_path_list(t_list *path_list);
void	display_graph(t_graph *graph);

/// destroy_graph.c

void	destroy_graph(t_graph *);

/// get_info_graph.c

bool	is_graph_complete(t_graph *graph);

///////////////// ROOM

/// create_room.c

t_room	*create_room(const char *input_name, t_list *list);
void	create_n_add_room(t_list **list, t_room **room, const char *name);
void	find_or_add(t_list **list, t_room **room, const char *name);

/// get_info_room.c

t_room	*find_room(t_list *list, const char *name);

/// destroy_room.c

void	destroy_room(t_room **room);

/// display_room.c

void	display_room(t_room *room);
void	full_display_room(t_room *room);

///////////////// PATH

/// struct_path.c

void	extract_path(t_graph *graph, t_list **path);

/// path_finder.c

void	path_finder(t_graph *graph, t_room *room, t_list **path);
void	get_shortest_paths(t_graph *graph);

///////////////// INSTRUCTIONS

/// find_inst.c

bool	is_valid_arg(char *arg, const char *pattern);
char	*is_start_inst(const char *);
char	*is_end_inst(const char *);
char	*is_link_inst(const char *);

/// exe_inst.c

result	start(t_graph *, const char *command);
result	end(t_graph *, const char *command);
result	ft_link(t_graph *, const char *command);

/// instructions.c

result	get_inst(const char *);
result	display(const char *line);

#endif
