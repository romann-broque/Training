/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:52:50 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/23 17:48:10 by romannbroque     ###   ########.fr       */
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

typedef	struct	s_node
{
	void			*name;
	struct s_node	*link;
}					t_node;

typedef struct	s_room
{
	char	*id;
	bool	discovered;
	t_node	*link;
}			t_room;

typedef	struct	s_gallery
{
	t_room				*room;
	struct s_gallery	*link;
}						t_gallery;

typedef	struct	s_queue
{
	int		count;
	t_node	*front;
	t_node	*rear;
}			t_queue;

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
t_room	*find_room(t_gallery *head, void *id);
bool	is_room_exist(t_gallery *head, void *name);

///////////// display_room.c

void	display_room(t_room *n);
void	display_list_room(t_node *prev);

////////////////////////////////////////////////////////////////////////////////

void	display_error(int state);

////////////////////////////////////////////////////////////////////////////////

///////////// display.c

void	display_list(t_node *prev);

///////////// get_info.c

size_t	get_size(t_node **prev);

///////////// linked_list.c

t_node	*linked_list(int node_number, void *data);

///////////// pop.c

void	pop(t_node **prev);
void	cut(t_node **prev);
void	delete_data(t_node **prev, void *input_data);

///////////// push.c

void	add(t_node *prev, void *input_data);
void	insert(t_node **prev, void *input_data, size_t rank);
void	push(t_node **prev, void *input_data);

///////////// reverse.c

void	reverse_list(t_node **root);

//////////// struct.c

t_node	*create_node(void *input_data);
void	destroy_node(t_node **prev);
void	destroy_list(t_node **prev);

////////////////////////////////////////////////////////////////////////////////

///////////// struct_gallery.c

t_gallery	*create_gallery(void *id);
void		add_gallery(t_gallery *head, void *id);

///////////// display_gallery.c

void	display_gallery(t_gallery *head);

////////////////////////////////////////////////////////////////////////////////

///////////// path_finder.c

void	dfs(t_room *start, t_room *end);
void	bfs(t_room *start, t_room *end);

////////////////////////////////////////////////////////////////////////////////

///////////// struct_queue.c

t_queue	*init_queue(void);
bool	is_empty(t_queue *queue);
void	enqueue(t_queue *queue, t_node *node);
void	*dequeue(t_queue *queue);

///////////// display_queue.c

void	display_queue(t_queue *queue);

////////////////////////////////////////////////////////////////////////////////

///////////// instructions.c

int		inst(char *line, t_gallery **rooms, char *path[2]);
int		start(char *arg, char *path[2]);
int		end(char *arg, char *path[2]);
int		link_room(char *line, t_gallery **rooms);

///////////// utilities.c

size_t	str_len(const char *str);
bool	ft_strchr(const char *str, const char c);
bool	are_same_str(char *str1, char *str2);
char 	*ft_strcpy(char *dest, const char *src);

#endif
