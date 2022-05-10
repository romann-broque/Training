/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:10:25 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/11 15:03:05 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H

# define UTILITIES_H

# include <stdbool.h>

size_t	ft_strlen(const char *str);
bool	ft_strchr(const char *str, const char c);
bool	are_same_str(const char *str1, const char *str2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *str);

#endif
