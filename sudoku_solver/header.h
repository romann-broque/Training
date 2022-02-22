/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:16:31 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/22 19:04:48 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE_GRID 9
#define UNKNOWN '.'
#define SUM 45
#define SPACE ' '

//check.c//

bool	is_solution_unique(char **grid);
bool	is_correct(char **grid, size_t *coord);

//display.c//

void	ft_putchar(const char c);
void	ft_putstr(const char *str);
void	display_line(const char *line);
void	display_grid(char **grid);
void	display_error(void);

//initialisation.c//

char	**init_grid(char **arg);
size_t	*init_coord();

//lexing.c//

bool	is_correct_char(const char c);
bool	are_correct_char(const char **grid);
bool	is_still_unknown(char **grid);
bool	is_strchr(const char *str, const char c);

//part_check.c//

bool	can_be_changed(char **orig_grid, char **curr_grid, size_t *coord);
bool	is_str_correct(const char *str);
bool	is_line_correct(char *line);
bool	is_column_correct(char **grid, size_t column_index);
bool	is_block_correct(char **grid, size_t *coord);

//resolution.c//

bool	go_foward(size_t *coord);
void	go_back_to_last_changed_number(char **orig_grid, char **curr_grid, size_t *coord);
void	sudoku_solver(char **orig_grid, char **curr_grid, size_t *coord);

//utilities.c//

int		sum_number_from_str(const char *str);
int		get_n_from_char(const char c);
size_t	str_len(const char *str);
size_t	len(const char **str);
void	desalloc(char **strs, size_t max);
bool	are_double_numbers(const char *str);
bool	is_double(const char *str);
