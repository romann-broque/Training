/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:07:56 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/12 15:58:14 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H

# define UTILITIES_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

///string.c

char	*ft_strdup(const char *str);
void	ft_strcpy(char *dest, const char *src);
char	*ft_strcat(const char *str1, const char *str2);

///get_info.c

size_t	ft_strlen(const char *str);
bool	ft_strchr(const char *str, const char c);
bool	is_empty(const char *str, const size_t size);

///remove.c

void	ft_bzero(void *array, const size_t size);
void	cut_str(char *str, const char c);

///display.c

void	ft_putstr(const char *str);

#endif
