/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:52:50 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/24 12:24:21 by romannbroque     ###   ########.fr       */
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

# include <stdio.h>

# define PATH_FILE "/Users/romannbroque/Desktop/Code/C_project/Training/mini_lem_in/includes/file.txt"
# define START_PATTERN "#start "
# define END_PATTERN "#end "
# define SEPARATOR "-"
# define DELIM "-"
# define MIN_SIZE 1
# define NBOF_INST 3
# define BUFFER_SIZE 4
# define EMPTY_LINE "\0"

typedef	struct	s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

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

/////////////// gnl.c

char	*get_next_line(int fd);

/////////////// line_editor.c

char	*init_buf(void);
char	*keep_beginning(char *str, size_t rank);
char	*keep_end(char *str, size_t rank);

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
bool	is_room_exist(t_list *head, void *name);

///////////// display_room.c

void	display_room(t_room *n);
void	display_list_room(t_list *prev);

////////////////////////////////////////////////////////////////////////////////

void	display_error(int state);

////////////////////////////////////////////////////////////////////////////////

///////////// display.c

void	display_list(t_list *prev);

///////////// get_info.c

size_t	get_size(t_list **prev);

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
