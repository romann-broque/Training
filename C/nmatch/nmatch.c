/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:39:10 by romannbroque      #+#    #+#             */
/*   Updated: 2022/02/01 23:54:15 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define META_CHAR '*'

int	nmatch(char *s1, char *s2)
{
	if ((s1 == NULL) || (s2 == NULL))
		return (0);
	else if ((*s1 == '\0') && (*s2 == '\0'))
		return (1);
	else if ((*s2 == META_CHAR) && (*s1 == '\0'))
		return (nmatch(s1, s2 + 1));
	else if (*s2 == META_CHAR)
		return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
	else if (*s1 == *s2)
		return (nmatch(s1 + 1, s2 + 1));
	return (0);
}
