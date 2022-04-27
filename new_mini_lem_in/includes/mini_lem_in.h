/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:53:43 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/27 15:09:21 by romannbroque     ###   ########.fr       */
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
#define GET NULL

typedef struct s_graph
{
	t_list	*rooms;
	char	*start;
	char	*end;
}			t_graph;

///create_graph.c

t_graph	*init_graph(void);
t_graph *graph_keeper(t_graph *graph);
t_graph *get_graph(void);
void	 set_graph(t_graph *graph);

///display_graph.c

void	display_graph(t_graph **graph);

///destroy_graph.c

void	destroy_graph(t_graph **);

///find_inst.c

bool	is_start_inst(const char *);
bool	is_end_inst(const char *);
bool	is_link_inst(const char *);

///exe_inst.c

int		start(t_graph **, const char *command);
int		end(t_graph **, const char *command);
int		ft_link(t_graph **, const char *command);

///instructions.c

void	*get_inst(const char *);
void	*display(const char *line);

#endif
