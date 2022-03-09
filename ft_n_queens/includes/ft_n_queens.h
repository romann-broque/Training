/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_queens.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:11:41 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/09 17:11:43 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EQ_H

#	include <unistd.h>
#	include <stdlib.h>
#	include <stdio.h>
#	include <stdbool.h>

#	define FT_EQ_H
#	define EMPTY '-'
#	define SIZE 8
#	define QUEEN_NB 8
#	define QUEEN 'Q'
#	define LAST_QUEEN_DOESNT_EXIST -1

#endif

///////////ft_eight_queens.c//

void	ft_eight_queens(void);

///////////display.c//

void	display_chessboard(char **chessboard);

///////////get_info.c//

size_t	str_len(char *str);
bool	is_queen(char *str);
bool	is_in_chessboard(int position);

///////////init.c//

char	**init_chessboard(void);

///////////is_valid.c//

bool	is_case_valid(char **chessboard, int position);

///////////back_tracking.c//

int		back_tracking(char **chessboard, int position, int queen);

///////////pos.c//

int		next_pos(int position);
void	turn_into(char **chessboard, int position, char new_c);
void	add_queen(char **chessboard, int position);
void	remove_queen(char **chessboard, int position);
