/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:53:43 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 14:54:05 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LEM_IN_H

# define MINI_LEM_IN_H

# include "gnl.h"
# include "linked_list.h"
# include "utilities.h"

# define NBOF_SUITE 6
# define NBOF_COM 3
# define NBOF_ERROR 5
# define START_PATTERN "#start "
# define END_PATTERN "#end "
# define DELIM "-"
# define DELIM_PATH "->"
# define DELIM_NEIGHBOOR ", "
# define GET NULL

enum e_error
{
	E_NO_ERROR,
	E_UNKNOWN_COMMAND,
	E_INCOMPLETE_GRAPH,
	E_START_ERROR,
	E_END_ERROR,
	E_INVALID_NAME_ERROR,
};

typedef struct s_room
{
	char	*name;
	bool	lock;
	t_list	*neighboor;
}			t_room;

typedef struct s_graph
{
	t_list	*rooms;
	t_list	*shortest_paths;
	t_room	*start;
	t_room	*end;
}			t_graph;

///////////////// GRAPH

/// create_graph.c

t_graph		*graph_keeper(t_graph *graph);
t_graph		*get_graph(void);
void		init_graph(t_graph *graph);
void		set_graph(t_graph *graph);

/// display_graph.c

void		display_graph(t_graph *graph);

/// destroy_graph.c

void		destroy_graph(t_graph *graph);

/// get_info_graph.c

bool		is_graph_complete(t_graph *graph);

///////////////// ROOM

/// create_room.c

t_room		*create_room(const char *input_name, t_list *list);
void		find_or_add(t_list **list, t_room **room, const char *name);

/// get_info_room.c

t_room		*find_room(t_list *list, const char *name);

/// destroy_room.c

void		destroy_room(t_room **room);

/// display_room.c

void		display_room(t_room *room);
void		full_display_room(t_room *room);

///////////////// PATH

/// struct_path.c

void		extract_path(t_graph *graph, t_list **path);

/// path_finder.c

void		path_finder(t_graph *graph, t_room *room, t_list *path);
void		get_shortest_paths(t_graph *graph);

/// display_path_list.c

void		display_path_list(t_list *path_list);

///////////////// INSTRUCTIONS

/// find_inst.c

bool			is_perfect_arg(const char *arg);
const char		*is_start_inst(const char *line);
const char		*is_end_inst(const char *line);
const char		*is_link_inst(const char *line);

/// exe_inst.c

t_result	start(t_graph *graph, const char *command);
t_result	end(t_graph *graph, const char *command);
t_result	ft_link(t_graph *graph, const char *command);

/// instructions.c

t_result	get_inst(const char *line);
t_result	display(const char *line);

/// error_manager.c

void		error_manager(t_result error);

#endif
