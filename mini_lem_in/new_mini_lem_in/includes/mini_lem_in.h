/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:52:50 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/28 18:34:51 by romannbroque     ###   ########.fr       */
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

unsigned int	get_arg_size_from_str(char *str, char end_char);
char			*get_arg_from_str(char *str, char end_char);

////////////////////////////////////////////////////////////////////////////////

///////////// create_struct.c

t_room	*create_room(char *id);
t_list	*create_list_room(char *name);
t_room	*add_neighboor(t_room *parent, t_room *child);
void	add_room(t_list *list, char *name);
t_room	*find_room(t_list *head, char *name);
bool	does_room_exist(t_graph *graph, char *name);

///////////// display_room.c

void	display_room(t_room *n);
void	display_list_room(t_list *prev);

////////////////////////////////////////////////////////////////////////////////

void	display_error(int state);

////////////////////////////////////////////////////////////////////////////////

///////////// struct_graph.c

t_graph	*init_graph(void);
void	display_graph(t_graph *graph);

////////////////////////////////////////////////////////////////////////////////

///////////// struct_path.c

t_path	*create_path(t_room *first_room);
t_list	*init_path_list(t_room *start);
void	add_step(t_path *path, t_room *new_room);
t_room	*get_last_room(t_path *path);
void	display_path_list(t_list *path_list);

///////////// path_finder.c

void	display_shortest_paths(t_graph *graph);
void	path_finder(t_graph *graph, t_list *path_list, t_room *curr_room);

////////////////////////////////////////////////////////////////////////////////

///////////// instructions.c

int		inst(t_graph *graph, char *line);
int		start(t_graph *graph, char *arg);
int		end(t_graph *graph, char *arg);
int		link_room(t_graph *graph, char *line);

///////////// utilities.c

size_t	str_len(const char *str);
bool	ft_strchr(const char *str, const char c);
bool	are_same_str(char *str1, char *str2);
char 	*ft_strcpy(char *dest, const char *src);

#endif
