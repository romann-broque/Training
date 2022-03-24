/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:52:50 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/24 17:48:45 by romannbroque     ###   ########.fr       */
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
t_room	*add_room(t_room *parent, t_room *child);
t_room	*find_room(t_list *head, void *id);

///////////// display_room.c

void	display_room(t_room *n);
void	display_list_room(t_list *prev);

////////////////////////////////////////////////////////////////////////////////

void	display_error(int state);

////////////////////////////////////////////////////////////////////////////////

///////////// struct_list.c

t_graph	*init_graph(void);

///////////// display_gallery.c

void	display_gallery(t_list *head);

////////////////////////////////////////////////////////////////////////////////

///////////// path_finder.c

void	dfs(t_room *start, t_room *end);
void	bfs(t_room *start, t_room *end);

////////////////////////////////////////////////////////////////////////////////

///////////// instructions.c

int		inst(t_graph *graph, char *line, char *path[2]);
int		start(char *arg, char *path[2]);
int		end(char *arg, char *path[2]);
int		link_room(t_list *rooms, char *line);

///////////// utilities.c

size_t	str_len(const char *str);
bool	ft_strchr(const char *str, const char c);
bool	are_same_str(char *str1, char *str2);
char 	*ft_strcpy(char *dest, const char *src);

#endif
