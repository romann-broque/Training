/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:52:52 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/23 15:35:20 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include <stdlib.h>
# include <stdio.h>

# define NEW_LINE "\n"
# define OPERATORS "+-*/%"

int	add(const int nb1, const int nb2);
int	sub(const int nb1, const int nb2);
int	mult(const int nb1, const int nb2);
int	division(const int nb1, const int nb2);
int	mod(const int nb1, const int nb2);

#endif
