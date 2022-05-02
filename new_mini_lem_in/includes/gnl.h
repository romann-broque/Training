/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:02:53 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 19:37:51 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H

# define GNL_H

# include "utilities.h"

# define BUFFER_SIZE 4

char		*get_next_line(const int fd);
t_result	read_file(const char *path_file,
				t_result (*function)(const char *));

#endif
