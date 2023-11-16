/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:47:00 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/20 00:14:16 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

ssize_t	ft_putchar(const char c, const int fd)
{
	ssize_t	result;

	result = write(fd, &c, sizeof(char));
	if (result == -1)
		perror("ft_putchar error");
	return (result);
}
