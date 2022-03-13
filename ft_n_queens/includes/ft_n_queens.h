/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_queens.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:11:41 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/13 23:17:27 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EQ_H

# define FT_EQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define EMPTY '-'
# define SIZE 3
# define QUEEN_NB 2
# define QUEEN 'Q'
# define LAST_QUEEN_DOESNT_EXIST -1

///////////ft_n_queens.c//

int	ft_n_queens(void);

///////////display.c//

void	display_chessboard(char **chessboard);

///////////get_info.c//

size_t	str_len(char *str);
bool	is_queen(char *str);
bool	is_in_chessboard(int position);
char	read_case(char **chessboard, int position);

///////////init.c//

char	**init_chessboard(void);

///////////is_valid.c//

bool	is_case_valid(char **chessboard, int position);
bool	are_diags_valid(char **chessboard, int position);
bool	is_column_valid(char **chessboard, int column);

///////////back_tracking.c//

int		back_tracking(char **chessboard, int position, int queen);

///////////edit_case.c//

int		next_pos(int position);
void	turn_into(char **chessboard, int position, char new_c);
void	add_queen(char **chessboard, int position);
void	remove_queen(char **chessboard, int position);

///////////get_pos.c//

int	get_lign(int position);
int	get_column(int position);
int	get_pos_from_coord(int lign, int column);
int	next_pos(int position);

#endif
