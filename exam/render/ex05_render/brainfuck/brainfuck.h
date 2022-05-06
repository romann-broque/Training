/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:23:40 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/06 16:56:45 by romannbroque     ###   ########.fr       */
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


/// utilities.c

void	ft_putchar(const char c);
void	ft_bzero(void *ptr, const size_t size);

/// op_fct.c

void	*increment_ptr(void **array);
void	*decrement_ptr(void **array);
void	*increment_byte(void **array);
void	*decrement_byte(void **array);
void	*print(void **array);

/// while_fct.c

void	*while_start(void **array, const char **command);
void	*while_end(void **array, const char **command);

#endif
