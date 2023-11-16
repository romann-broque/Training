/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:21:18 by romannbroque      #+#    #+#             */
/*   Updated: 2022/06/27 18:22:10 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CALC_H
# define RPN_CALC_H

#define OPERATORS "+-*/%"

long	add(const int nb1, const int nb2);
long	sub(const int nb1, const int nb2);
long	mult(const int nb1, const int nb2);
long	divide(const int nb1, const int nb2);
long	mod(const int nb1, const int nb2);

#endif
