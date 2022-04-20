/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:53:43 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/20 15:45:19 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LEM_IN_H

#define MINI_LEM_IN_H

# include "gnl.h"
# include "linked_list.h"
# include "utilities.h"

# define NBOF_SUITE 3
# define NBOF_COM 3
# define START_PATTERN "#start "
# define END_PATTERN "#end "
# define DELIM "-"


///find_inst.c

bool	is_start_inst(const char *);
bool	is_end_inst(const char *);
bool	is_link_inst(const char *);

///exe_inst.c


int		start(const char *command);
int		end(const char *command);
int		ft_link(const char *command);

///instructions.c

void	get_inst(const char *);

#endif
