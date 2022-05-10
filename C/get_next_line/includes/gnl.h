/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:52:28 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/16 15:33:56 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H

# define GNL_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define PATH_FILE "/Users/romannbroque/Desktop/Code/C_project/Training/get_next_line/includes/file.txt"
# define BUFFER_SIZE 4
# define EMPTY_LINE "\0"

/////////////// gnl.c

char	*get_next_line(int fd);

/////////////// gnl.c

bool	ft_strchr(char *str, const char c);
size_t	str_len(char *str);
char	*init_buf(void);

char	*keep_beginning(char *str, size_t rank);
char	*keep_end(char *str, size_t rank);

#endif
