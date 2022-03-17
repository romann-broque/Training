/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:52:50 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/17 23:46:00 by romannbroque     ###   ########.fr       */
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
# define DELIM '-'
# define MIN_SIZE 1
# define NBOF_INST 3
# define BUFFER_SIZE 4
# define EMPTY_LINE "\0"

typedef	struct	s_node
{
	char			*name;
	struct s_node	*link;
}					t_node;

typedef struct	s_room
{
	char			*id;
	struct s_room	**link;
	size_t			link_cnt;
}					t_room;

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
t_room	*add_room(t_room *n1, t_room *n2);
void	display_room(t_room *n);

////////////////////////////////////////////////////////////////////////////////

void	display_error(int state);

////////////////////////////////////////////////////////////////////////////////

///////////// display.c

void	display_list(t_node *prev);

///////////// get_info.c

size_t	get_size(t_node **prev);

///////////// linked_list.c

t_node	*linked_list(int node_number, char **data);

///////////// pop.c

void	pop(t_node **prev);
void	cut(t_node **prev);
void	delete_data(t_node **prev, char *input_data);

///////////// push.c

void	add(t_node *prev, char *input_data);
void	insert(t_node **prev, char *input_data, size_t rank);
void	push(t_node **prev, char *input_data);

///////////// reverse.c

void	reverse_list(t_node **root);

//////////// struct.c

t_node	*create_node(char *input_data);
void	destroy_node(t_node **prev);
void	destroy_list(t_node **prev);

////////////////////////////////////////////////////////////////////////////////

///////////// instructions.c

int		inst(char *line);
void	start(char *arg);
void	end(char *arg);
void	link_room(char *arg1, char *arg2);

///////////// utilities.c

size_t	str_len(const char *str);
bool	ft_strchr(const char *str, const char c);

#endif
