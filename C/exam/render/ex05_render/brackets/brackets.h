/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:09:18 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/08 16:22:45 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRACKETS_H
# define BRACKETS_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

# define OPENED "([{"
# define CLOSED ")]}"
# define INITIAL_CONTEXT '\0'

size_t	ft_strlen(const char *str);
void	ft_putstr(const char *str);
char	*ft_strchr(const char *str, const char c);

#endif
