/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:52:50 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/17 22:17:10 by romannbroque     ###   ########.fr       */
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
# define DELIM '-'
# define NBOF_INST 3
# define BUFFER_SIZE 4
# define EMPTY_LINE "\0"

typedef struct	nd
{
	char		*id;
	struct nd	**link;
	size_t		link_cnt;
}				node;

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

node	*create_node(char *id);
node	*add_node(node *n1, node *n2);
void	display_node(node *n);

////////////////////////////////////////////////////////////////////////////////

void	display_error(int state);

////////////////////////////////////////////////////////////////////////////////

///////////// instructions.c

int		inst(char *line);
void	start(char *arg);
void	end(char *arg);
void	link_nodes(char *arg1, char *arg2);

///////////// utilities.c

size_t	str_len(const char *str);
bool	ft_strchr(const char *str, const char c);

#endif
