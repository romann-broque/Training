/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:23:40 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/08 16:38:31 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINFUCK_H

# define BRAINFUCK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define OPERATORS "[]><+-."
# define NBOF_OPERATORS 5
# define NBOF_WHILE 2
# define WHILE_START '['
# define WHILE_END ']'

typedef char t_byte;
/// utilities.c

void	ft_putchar(const char c);
void	ft_bzero(void *ptr, const size_t size);

/// op_fct.c

void	increment_ptr(t_byte **array);
void	decrement_ptr(t_byte **array);
void	increment_byte(t_byte **array);
void	decrement_byte(t_byte **array);
void	print(t_byte **array);

/// while_fct.c

void	while_start(t_byte **array, const char **command);
void	while_end(t_byte **array, const char **command);

#endif
