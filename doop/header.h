/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:47:26 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/25 12:02:35 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

#define VALID_CHAR " \t"
#define OPERATORS "+-*/%"
#define NUMB_OF_OP 5

//clean_arg.c/////////////

char *trim(char *str);

//checks.c////////////////

bool	is_numb(const char c);
bool	is_valid_number(char *str);

//utilities.c/////////////

size_t	str_len(const char *str);
long	power(int nb, unsigned int p);

//get_n.c/////////////////

int					get_n_from_str(char *str);
unsigned int		get_n_size_from_str(char *str);
unsigned int		get_n_size(const long n);

//operations.c////////////

long	add(long n1, long n2);
long	sub(long n1, long n2);
long	mult(long n1, long n2);
long	division(long n1, long n2);
long	mod(long n1, long n2);

//errors.c///////////////

void	invalid_numb_error(void);
void	invalid_operator_error(void);
void	null_arg_error(void);
void	division_by_zero_error(void);

//display.c//////////////

void	ft_putchar(const char c);
void	ft_putstr(const char *str);
void	ft_put_longnbr(long n);
void	display_result(int n1, char op, int n2, long result);
