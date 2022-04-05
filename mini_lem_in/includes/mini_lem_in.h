/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:52:50 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/04 15:07:25 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LEM_IN_H

# define MINI_LEM_IN_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include "utilities.h"
# include "gnl.h"
# include "linked_list.h"

# include <stdio.h>

# define START_PATTERN "#start "
# define END_PATTERN "#end "
# define DELIM "-"
# define MIN_SIZE 1
# define NBOF_INST 3

enum e_error
{
	E_NO_ERROR,
	E_UNKNOWN_COMMAND,
	E_START_DOESNT_EXIST,
	E_END_DOESNT_EXIST,
	E_MISSING_START,
	E_MISSING_END,
	E_MISSING_NODE,
	E_START_NOT_UNIQUE,
	E_END_NOT_UNIQUE,
	E_NO_NODE,
};

typedef struct	s_room
{
	char	*name;
	bool	lock;
	t_list	*neighboor;
}			t_room;

typedef struct	s_path
{
	size_t	size;
	t_list	*step;
}			t_path;

typedef struct s_graph
{
	t_list	*rooms;
	t_list	*shortest_paths;
	t_room	*start;
	t_room	*end;
}			t_graph;

////////////////////////////////////////////////////////////////////////////////

///////////// parser.c

bool	is_start_inst(char *line);
bool	is_end_inst(char *line);
bool	is_link_inst(char *line);

///////////// get_nb.c

char	*get_arg_from_str(const char *str, const char end_char);

////////////////////////////////////////////////////////////////////////////////

///////////// struct_room.c

t_room	*create_room(char *id);
t_list	*create_list_room(char *name);
void	add_neighboor(t_room *parent, t_room *child);
void	add_room(t_list *list, char *name);
void	destroy_room(t_room *room);
void	destroy_list_room(t_list *room);

t_room	*find_room(t_list *head, char *name);
bool	does_room_exist(t_graph *graph, char *name);

///////////// display_room.c

void	display_room(t_room *n);
void	display_list_room(t_list *prev);

////////////////////////////////////////////////////////////////////////////////

int		display_error(int state);

////////////////////////////////////////////////////////////////////////////////

///////////// struct_graph.c

t_graph	*init_graph(void);
void	destroy_graph(t_graph *graph);
int		is_graph_correct(t_graph *graph);

///////////// display_graph.c

void	display_graph(t_graph *graph);

////////////////////////////////////////////////////////////////////////////////

///////////// struct_path.c

t_path	*create_path(t_room *first_room);
void	destroy_path_list(t_list *path_list);
void	cut_path(t_list **path);
void	extract_path(t_graph *graph, t_list **path);

///////////// path_finder.c

void	path_finder(t_graph *graph, t_room *curr_room, t_list **path);
void	get_shortest_paths(t_graph *graph);

///////////// find_shortest_paths.c

int		find_shortest_paths(void);

///////////// display_path.c

void	display_path_list(t_list *path_list);

////////////////////////////////////////////////////////////////////////////////

///////////// instructions.c

int		inst(t_graph *graph, char *line);
int		start(t_graph *graph, char *arg);
int		end(t_graph *graph, char *arg);
int		link_room(t_graph *graph, char *line);

#endif
