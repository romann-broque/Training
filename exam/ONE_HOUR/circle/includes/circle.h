/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:01:49 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/03 20:07:50 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_H

# define CIRCLE_H

# include <unistd.h>
# include <stdlib.h>

# define CHAR '*'

/// display

size_t	ft_strlen(const char *str);
void	ft_putchar(const char c);
void	ft_putstr(const char *str);
void	repeat_display(const char c, int size);
void	display_map(char **map, int size);

#endif
