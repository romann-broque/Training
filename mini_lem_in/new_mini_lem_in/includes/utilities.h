/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:10:25 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/24 17:11:24 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H

# define UTILITIES_H

# include <stdbool.h>

size_t	str_len(const char *str);
bool	ft_strchr(const char *str, const char c);
bool	are_same_str(char *str1, char *str2);
char	*ft_strcpy(char *dest, const char *src);

#endif
