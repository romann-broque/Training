/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:46:33 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/09 11:36:23 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EQ_H

#	include <unistd.h>
#	include <stdlib.h>
#	include <stdio.h>
#	include <stdbool.h>

#	define FT_EQ_H
#	define SIZE 8
#	define EMPTY '-'
#	define QUEEN 'X'
#	define QUEEN_NB 8
#	define LAST_QUEEN_DOESNT_EXIST -1

#endif

///////////ft_eight_queens.c//

void	ft_eight_queens(void);

///////////display.c//

void	display_chessboard(char **chessboard);

///////////get_info.c//

size_t	str_len(char *str);
bool	is_queen(char *str);
int		is_count_queens(char **str);

///////////init.c//

char	**init_chessboard(void);

///////////is_valid.c//

bool	is_in_chessboard(int position);
bool	is_valid(char **chessboard, int position);

///////////back_tracking.c//

int	back_tracking(char **chessboard, int position);

///////////pos.c//

int		next_pos(int position);
int		prev_pos(int position);
int		last_queen(char **chessboard, int position);
void	turn_into(char **chessboard, int position, char new_c);
