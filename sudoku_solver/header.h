/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:16:31 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/16 23:21:16 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE_GRID 9
#define UNKNOWN '.'
#define SUM 45

void	ft_putchar(const char c);
void	display_grid(char **grid);
void	display_error(void);

char	**init_grid(char **lines, char **arg);

bool	is_correct_char(const char c);
bool	are_correct_char(const char **grid);
bool	is_still_unknown(char **grid);

bool	is_solution_unique(char **grid);
bool	is_line_correct(char *line);
bool	is_column_correct(char **grid, size_t column_index);
bool	is_block_correct(char **grid, size_t line_index, size_t column_index);
bool	is_correct(char **grid, size_t line_index, size_t column_index);

unsigned int	sum_number_from_str(char *str);
void	try_next_number(char **grid, size_t line_index, size_t column_index);
void	sudoku_solver(char **grid, size_t line_index, size_t column_index);

size_t	str_len(const char *str);
size_t	len(const char **str);
void	desalloc(char **strs, size_t max);

