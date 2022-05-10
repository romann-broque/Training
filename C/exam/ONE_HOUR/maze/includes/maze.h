/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:01:12 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 16:54:48 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAZE_H

# define MAZE_H

# include "gnl.h"
# include "utilities.h"

typedef int t_result;

size_t	count_lines(const char *path_file);
size_t	max_len(const char *path_file);
char	*init_map(const char *path_file);

#endif
