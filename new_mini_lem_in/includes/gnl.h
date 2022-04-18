/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:02:53 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/18 17:36:29 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H

# define GNL_H

# include "utilities.h"

# define BUFFER_SIZE 4

char	*get_next_line(const int fd);
void	read_file(const char *path_file, void function(const char *));

#endif
