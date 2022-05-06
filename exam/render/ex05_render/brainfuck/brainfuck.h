/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:23:40 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/06 00:05:36 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_FUCK_H

# define BRAIN_FUCK_H

# include <unistd.h>
# include <stdlib.h>
# define OPERATORS "><+-.[]"
# define NUMBOF_OPERATORS 7

void	ft_putchar(const char c);
void	ft_bzero(void *ptr, const size_t size);
void	*increment_ptr(void *array);
void	*decrement_ptr(void *array);
void	*increment_byte(void *array);
void	*decrement_byte(void *array);
void	*print(void *array);

#endif
