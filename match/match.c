/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:20:05 by romannbroque      #+#    #+#             */
/*   Updated: 2022/01/30 18:37:20 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define UNIVERSAL_CHAR '*'

int	match(char *str1, char *str2)
{
	if ((str1 == NULL) && (str2 == NULL))
		return (1);
	else if ((str1 == NULL) || (str2 == NULL))
		return (0);
	else if ((*str1 == '\0') && (*str2 == '\0'))
		return (1);
	else if ((*str2 == UNIVERSAL_CHAR) && (*str1 == '\0'))
		return (match(str1, str2 + 1));
	else if (*str2 == UNIVERSAL_CHAR)
		return (match(str1 + 1, str2) || match(str1, str2 + 1));
	else if (*str1 == *str2)
		return (match(str1 + 1, str2 + 1));
	return (0);
}
